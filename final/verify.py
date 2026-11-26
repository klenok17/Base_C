"""Необязательная проверка преподавателем: python3 verify.py.
Программа задания написана на C; Python нужен только для этих проверок.
Все временные файлы создаются вне исходного проекта.
"""
from pathlib import Path
import subprocess
import datetime
import re
import tempfile

ROOT = Path(__file__).resolve().parent
CHECKS = 0


def check(condition, message):
    global CHECKS
    if not condition:
        raise AssertionError(message)
    CHECKS += 1


def build(target, *extra, source=None):
    sources = [str(source)] if source else [str(ROOT / "main.c")]
    result = subprocess.run(
        ["gcc", "-std=c11", "-Wall", "-Wextra", "-Wpedantic", "-Werror",
         "-I", str(ROOT), *extra, *sources, str(ROOT / "temp_functions.c"), "-o", str(target)],
        capture_output=True, text=True,
    )
    check(result.returncode == 0, result.stderr)


with tempfile.TemporaryDirectory(prefix="temperature_final_") as directory:
    work = Path(directory)
    exe = work / "prog"
    build(exe, "-fsanitize=undefined", "-fno-sanitize-recover=all")

    def run(*args, binary=exe, input_text=None):
        return subprocess.run([str(binary), *map(str, args)], input=input_text,
                              capture_output=True, text=True, timeout=20)

    def fixture(name, text):
        path = work / name
        path.write_text(text, encoding="utf-8")
        return path

    r = run("-h")
    check(r.returncode == 0 and all(k in r.stdout for k in ("-h", "-f", "-m", "-i")), "help")
    check(run().returncode == 0, "no arguments")
    r = run("-f", ROOT / "temperature.csv", "-m", 1)
    check(r.returncode == 0 and "-8.50 C" in r.stdout, "January average")
    check("Минимальная температура: -12 C" in r.stdout and "Максимальная температура: -5 C" in r.stdout, "January extremes")
    check("Среднегодовая" not in r.stdout and "Месяц 02" not in r.stdout, "month filter")
    r = run("-f", ROOT / "temperature.csv")
    check(r.returncode == 0 and "Среднегодовая температура: 2.00 C" in r.stdout, "year average")
    check(r.stdout.count("Месяц ") == 12 and "Максимальная температура: 28 C" in r.stdout, "12 months and maximum")
    r = run("-f", ROOT / "temperature.csv", "-m", 4)
    check(r.returncode == 0 and r.stdout.count("нет данных") == 3, "empty month")
    for option in ("0", "13", "1x", "999999999999999999999", "-1"):
        check(run("-f", ROOT / "temperature.csv", "-m", option).returncode != 0, "invalid month " + option)
    for args in (("-f",), ("-m",), ("-z",), ("-m", "1"), ("-f", work / "absent.csv")):
        check(run(*args).returncode != 0, "invalid arguments " + str(args))

    r = run("-f", ROOT / "temperature_errors.csv", "-m", 1)
    check(r.returncode == 0 and "-8.50 C" in r.stdout, "skip invalid records")
    check("Пропущено записей: 3" in r.stderr and all(str(n) in r.stderr for n in (3, 5, 6)), "bad line diagnostics")
    for name, text in (("empty.csv", ""), ("header.csv", "year;month;day;hour;minute;temperature\n"), ("bad.csv", "2026,1,1,0,0,2\n")):
        check(run("-f", fixture(name, text)).returncode != 0, name)
    for name, text in (("last.csv", "2026;01;01;00;00;-99"), ("crlf.csv", "2026;01;01;00;00;99\r\n"), ("spaces.csv", "2026 ; 01 ; 01 ; 00 ; 00 ; +9\n")):
        check(run("-f", fixture(name, text)).returncode == 0, name)
    for name, text in (("overflow.csv", "4294969322;01;01;00;00;10\n"), ("trailing.csv", "2026;1;1;0;0;5junk\n"), ("extra.csv", "2026;1;1;0;0;5;6\n"), ("temp.csv", "2026;1;1;0;0;-100\n"), ("date.csv", "2026;2;29;0;0;1\n")):
        check(run("-f", fixture(name, text)).returncode != 0, name)
    check(run("-f", fixture("leap.csv", "2024;02;29;23;59;1\n")).returncode == 0, "leap day")
    r = run("-f", fixture("long.csv", "9" * 600 + "\n2026;1;1;0;0;5\n"))
    check(r.returncode == 0 and "Записей: 1" in r.stdout and "Строка 1" in r.stderr, "long line recovery")

    data = "2026;1;3;0;0;-10\n2026;1;1;0;0;-2\n2026;2;1;0;0;12\n"
    growth = "".join(f"2026;01;{i % 28 + 1:02d};00;00;{i % 199 - 99}\n" for i in range(1000))
    path = fixture("growth.csv", growth)
    r = run("-f", path)
    check(r.returncode == 0 and "Записей: 1000" in r.stdout, "multiple reallocations")
    expected_average = sum(i % 199 - 99 for i in range(1000)) / 1000
    check(f"Среднегодовая температура: {expected_average:.2f} C" in r.stdout, "statistics after growth")

    # Проверяем, что прежний фиксированный предел действительно снят.
    large = work / "over_old_limit.csv"
    with large.open("w", encoding="utf-8") as stream:
        for _ in range(600001):
            stream.write("2026;01;01;00;00;-7\n")
    r = run("-f", large, "-m", 1)
    check(r.returncode == 0 and "Записей: 600001" in r.stdout and
          "Среднемесячная температура: -7.00 C" in r.stdout and not r.stderr,
          "more than the old fixed capacity")

    path = fixture("edit.csv", data)
    r = run("-f", path, "-i", input_text="1\n2027 1 1 0 0 30\n1\n2026 1 2 0 0 4\n3\n4\n2\n1\n6\n5\n0\n")
    check(r.returncode == 0 and "Год записи должен совпадать" in r.stdout, "reject foreign year")
    check(all(s in r.stdout for s in ("Запись добавлена", "Запись удалена", "Массив отсортирован", "CSV сохранён")), "menu operations")
    check(path.read_text() == "year;month;day;hour;minute;temperature\n2026;01;02;00;00;4\n2026;01;03;00;00;-10\n2026;02;01;00;00;12\n", "sort/delete/save contents")
    check(run("-f", path).returncode == 0, "reload edited file")
    r = run("-f", path, "-i", input_text="2\n1\n2\n1\n2\n1\n3\n4\n6\n0\n")
    check(r.returncode == 0 and "Массив пуст" in r.stdout and "Нет измерений" in r.stdout, "empty after deletion")

    # Новые проверки итогового задания.
    uppercase = fixture("uppercase.csv", "YEAR;MONTH;DAY;HOUR;MINUTE;TEMPERATURE\n2026;01;01;00;00;5\n")
    check(run("-f", uppercase).returncode == 0, "uppercase header")
    bom = work / "bom.csv"
    bom.write_bytes(b"\xef\xbb\xbf" + uppercase.read_bytes())
    check(run("-f", bom).returncode == 0, "UTF-8 BOM")
    nul = work / "nul.csv"
    nul.write_bytes(b"2026;01;01;00;00;99\x00hidden\n2026;01;02;00;00;5\n")
    r = run("-f", nul)
    check(r.returncode == 0 and "Записей: 1" in r.stdout and "Строка 1:" in r.stderr, "embedded NUL rejected")
    r = run("-f", fixture("cr_tail.csv", "2026;1;1;0;0;99\rhidden\n2026;1;2;0;0;5\n"))
    check(r.returncode == 0 and "Записей: 1" in r.stdout and "Строка 1:" in r.stderr, "CR does not hide invalid suffix")
    row = "2026;1;1;0;0;5"
    exact = fixture("exact_length.csv", row + " " * (255 - len(row)))
    check(run("-f", exact).returncode == 0, "255 bytes without newline")
    log = work / "errors.log"
    r = run("-f", ROOT / "temperature_errors.csv", "-e", log)
    check(r.returncode == 0 and "Пропущено записей: 3" in r.stderr and "Строка 3:" not in r.stderr, "summary on screen")
    check(re.findall(r"Строка (\d+):", log.read_text()) == ["3", "5", "6"], "all bad line numbers in log")
    before = log.read_bytes()
    check(run("-f", ROOT / "temperature.csv", "-e", log).returncode != 0 and log.read_bytes() == before, "existing log is not overwritten")
    before = uppercase.read_bytes()
    check(run("-f", uppercase, "-e", uppercase).returncode != 0 and uppercase.read_bytes() == before, "input cannot become log")
    check(run("-f", uppercase, "-e", work / "missing_dir" / "errors.log").returncode != 0, "log creation error")
    check(run("-e").returncode != 0, "missing log argument")

    # Независимый расчёт по двум исходным CSV из задания.
    for filename in ("temperature_small.csv", "temperature_big.csv"):
        reference = []
        invalid_lines = []
        selected_year = None
        for number, line in enumerate((ROOT / filename).read_text().splitlines(), 1):
            try:
                fields = line.split(";")
                if len(fields) != 6:
                    raise ValueError("fields")
                y, m, day, hour, minute, temperature = map(int, fields)
                datetime.datetime(y, m, day, hour, minute)
                if not -99 <= temperature <= 99:
                    raise ValueError("temperature")
                if selected_year is None:
                    selected_year = y
                if y != selected_year:
                    raise ValueError("year")
                reference.append((m, temperature))
            except ValueError:
                invalid_lines.append(number)
        errors_path = work / (filename + ".log")
        r = run("-f", ROOT / filename, "-e", errors_path)
        check(r.returncode == 0 and f"Записей: {len(reference)}" in r.stdout, filename + " valid count")
        check(list(map(int, re.findall(r"Строка (\d+):", errors_path.read_text()))) == invalid_lines, filename + " exact rejected lines")
        for month in range(1, 13):
            values = [t for m, t in reference if m == month]
            section = r.stdout.split(f"Месяц {month:02d}:\n", 1)[1].split("\n\n", 1)[0]
            check(f"Среднемесячная температура: {sum(values)/len(values):.2f} C" in section and
                  f"Минимальная температура: {min(values)} C" in section and
                  f"Максимальная температура: {max(values)} C" in section, filename + f" month {month}")
        values = [t for m, t in reference]
        section = r.stdout.split(f"Статистика за {selected_year} год:\n", 1)[1]
        check(f"Среднегодовая температура: {sum(values)/len(values):.2f} C" in section and
              f"Минимальная температура: {min(values)} C" in section and
              f"Максимальная температура: {max(values)} C" in section, filename + " year")
        r = run("-f", ROOT / filename, "-m", "2")
        check(r.returncode == 0 and r.stdout.count("Месяц ") == 1 and
              "Среднегодовая" not in r.stdout, filename + " only February")
        check(list(map(int, re.findall(r"Строка (\d+):", r.stderr))) == invalid_lines, filename + " default diagnostics")

    api = work / "test_memory"
    app_object = work / "app_main.o"
    r = subprocess.run(["gcc", "-std=c11", "-Wall", "-Wextra", "-Wpedantic", "-Werror",
                        "-fsanitize=undefined", "-fno-sanitize-recover=all",
                        "-Dmain=temperature_main", "-c", str(ROOT / "main.c"), "-o", str(app_object)],
                       capture_output=True, text=True)
    check(r.returncode == 0, r.stderr)
    build(api, "-fsanitize=undefined", "-fno-sanitize-recover=all",
          str(app_object), "-Wl,--wrap=realloc", "-Wl,--wrap=free", source=ROOT / "test_memory.c")
    twenty = fixture("twenty.csv", "".join(f"2026;01;{i};00;00;{i}\n" for i in range(1, 21)))
    r = run(twenty, work / "absent.csv", binary=api)
    check(r.returncode == 0 and "MEMORY TESTS PASSED" in r.stdout, "memory test: " + r.stderr)
    check(r.stdout.count("Среднемесячная температура: -6.00 C") == 1 and
          "Среднегодовая температура: -6.00 C" in r.stdout, "original functions filter year")

print(f"PASS: {CHECKS} checks + memory assertions")
