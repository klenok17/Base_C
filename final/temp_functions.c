#include "temp_functions.h"
#include <stdio.h>
#include <stdlib.h>  /* qsort(), realloc(), free(). */
#include <limits.h>  /* INT_MAX: предел счётчиков, сохранённых из задания 12. */
#include <string.h>

void create_array(TemperatureArray *array)
{
    /* Буфер появится при первом добавлении. */
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
}

void free_array(TemperatureArray *array)
{
    free(array->data); /* free(NULL) тоже допустим. */
    create_array(array);
}

int grow_array(TemperatureArray *array)
{
    TemperatureRecord *new_data;
    size_t maximum = (size_t)-1 / sizeof(TemperatureRecord);
    int new_capacity;

    /* Число элементов должно помещаться и в int, и в размер блока памяти.
       Приведение -1 к беззнаковому size_t даёт его максимальное значение. */
    if (maximum > (size_t)INT_MAX)
        maximum = (size_t)INT_MAX;
    if ((size_t)array->capacity >= maximum)
        return 0;

    if (array->capacity == 0)
        new_capacity = maximum < 8 ? (int)maximum : 8;
    else if ((size_t)array->capacity > maximum / 2)
        new_capacity = (int)maximum;
    else
        new_capacity = array->capacity * 2;

    /* realloc(NULL, размер) выделяет первый блок.
       При расширении адрес может измениться. Поэтому сначала проверяем
       временный указатель: при отказе старый буфер остаётся доступным. */
    new_data = realloc(array->data, (size_t)new_capacity * sizeof(TemperatureRecord));
    if (new_data == NULL)
        return 0;
    array->data = new_data;
    array->capacity = new_capacity;
    return 1;
}

int valid_record(TemperatureRecord r)
{
    const int days_in_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int days, leap;
    if (r.year < 1 || r.year > 9999 || r.month < 1 || r.month > 12 ||
        r.hour < 0 || r.hour > 23 || r.minute < 0 || r.minute > 59 ||
        r.temperature < -99 || r.temperature > 99)
        return 0;
    leap = (r.year % 4 == 0 && r.year % 100 != 0) || r.year % 400 == 0;
    days = days_in_month[r.month - 1];
    if (r.month == 2 && leap)
        days = 29;
    return r.day >= 1 && r.day <= days;
}

int add_record(TemperatureArray *array, TemperatureRecord record)
{
    if (!valid_record(record))
        return 0;
    if (array->size > 0 && record.year != array->data[0].year)
        return 0;
    if (array->size == array->capacity && !grow_array(array))
        return 0;
    array->data[array->size] = record;
    array->size++;
    return 1;
}

int delete_record(TemperatureArray *array, int index)
{
    int i;
    if (index < 0 || index >= array->size)
        return 0;
    for (i = index; i + 1 < array->size; i++)
        array->data[i] = array->data[i + 1];
    array->size--;
    return 1;
}

int compare_dates(const void *left, const void *right)
{
    const TemperatureRecord *a = left;
    const TemperatureRecord *b = right;
    if (a->year != b->year) return a->year > b->year ? 1 : -1;
    if (a->month != b->month) return a->month > b->month ? 1 : -1;
    if (a->day != b->day) return a->day > b->day ? 1 : -1;
    if (a->hour != b->hour) return a->hour > b->hour ? 1 : -1;
    if (a->minute != b->minute) return a->minute > b->minute ? 1 : -1;
    return 0;
}

void sort_array(TemperatureArray *array)
{
    if (array->size < 2)
        return;
    qsort(array->data, (size_t)array->size, sizeof(array->data[0]), compare_dates);
}

void print_array(const TemperatureArray *array)
{
    int i;
    puts("Номер  Дата и время       Температура");
    for (i = 0; i < array->size; i++) {
        TemperatureRecord r = array->data[i];
        printf("%5d  %04d-%02d-%02d %02d:%02d  %d C\n",
               i + 1, r.year, r.month, r.day, r.hour, r.minute, r.temperature);
    }
    if (array->size == 0)
        puts("Массив пуст.");
}

/* Эти шесть функций заменяют заглушки, сохраняя интерфейс задания 11.
   Каждый расчёт явно отбирает записи нужного года, а месячный — и месяца. */
void print_month_average(const TemperatureRecord data[], int count, int year, int month)
{
    int i, found = 0;
    long long sum = 0;
    for (i = 0; i < count; i++) {
        if (data[i].year == year && data[i].month == month) {
            sum += data[i].temperature;
            found++;
        }
    }
    if (found == 0) puts("  Среднемесячная температура: нет данных");
    else printf("  Среднемесячная температура: %.2f C\n", (double)sum / found);
}

void print_month_min(const TemperatureRecord data[], int count, int year, int month)
{
    int i, found = 0, minimum = 0;
    for (i = 0; i < count; i++) {
        if (data[i].year == year && data[i].month == month) {
            if (!found || data[i].temperature < minimum)
                minimum = data[i].temperature;
            found = 1;
        }
    }
    if (!found) puts("  Минимальная температура: нет данных");
    else printf("  Минимальная температура: %d C\n", minimum);
}

void print_month_max(const TemperatureRecord data[], int count, int year, int month)
{
    int i, found = 0, maximum = 0;
    for (i = 0; i < count; i++) {
        if (data[i].year == year && data[i].month == month) {
            if (!found || data[i].temperature > maximum)
                maximum = data[i].temperature;
            found = 1;
        }
    }
    if (!found) puts("  Максимальная температура: нет данных");
    else printf("  Максимальная температура: %d C\n", maximum);
}

void print_year_average(const TemperatureRecord data[], int count, int year)
{
    int i, found = 0;
    long long sum = 0;
    for (i = 0; i < count; i++) {
        if (data[i].year == year) {
            sum += data[i].temperature;
            found++;
        }
    }
    if (found == 0) puts("  Среднегодовая температура: нет данных");
    else printf("  Среднегодовая температура: %.2f C\n", (double)sum / found);
}

void print_year_min(const TemperatureRecord data[], int count, int year)
{
    int i, found = 0, minimum = 0;
    for (i = 0; i < count; i++) {
        if (data[i].year == year) {
            if (!found || data[i].temperature < minimum)
                minimum = data[i].temperature;
            found = 1;
        }
    }
    if (!found) puts("  Минимальная температура: нет данных");
    else printf("  Минимальная температура: %d C\n", minimum);
}

void print_year_max(const TemperatureRecord data[], int count, int year)
{
    int i, found = 0, maximum = 0;
    for (i = 0; i < count; i++) {
        if (data[i].year == year) {
            if (!found || data[i].temperature > maximum)
                maximum = data[i].temperature;
            found = 1;
        }
    }
    if (!found) puts("  Максимальная температура: нет данных");
    else printf("  Максимальная температура: %d C\n", maximum);
}

void skip_spaces(const char **text)
{
    while (**text == ' ' || **text == '\t' || **text == '\r' || **text == '\n')
        (*text)++;
}

/* Преобразование выполняется по цифрам с проверкой ДО умножения на 10.
   Вызывается с небольшими границами: год, дата, температура, номер записи.
   minimum <= 0 допускает знак минус; INT_MIN как граница не используется. */
int parse_number(const char **text, int minimum, int maximum, int *value)
{
    const char *p = *text;
    int negative = 0, number = 0, digit, limit;
    skip_spaces(&p);
    if (*p == '+' || *p == '-') {
        negative = *p == '-';
        p++;
    }
    if (*p < '0' || *p > '9' || (negative && minimum >= 0))
        return 0;
    limit = negative ? -minimum : maximum;
    while (*p >= '0' && *p <= '9') {
        digit = *p - '0';
        if (number > limit / 10 || (number == limit / 10 && digit > limit % 10))
            return 0;
        number = number * 10 + digit;
        p++;
    }
    if (negative) number = -number;
    if (number < minimum || number > maximum)
        return 0;
    *value = number;
    *text = p;
    return 1;
}

int parse_record(const char *text, char separator, TemperatureRecord *record)
{
    int values[6], i;
    const int minimum[6] = {1, 1, 1, 0, 0, -99};
    const int maximum[6] = {9999, 12, 31, 23, 59, 99};
    const char *p = text;
    for (i = 0; i < 6; i++) {
        if (!parse_number(&p, minimum[i], maximum[i], &values[i]))
            return 0;
        if (i < 5) {
            if (separator == ' ') {
                if (*p != ' ' && *p != '\t') return 0;
                skip_spaces(&p);
            } else {
                skip_spaces(&p);
                if (*p != separator) return 0;
                p++;
            }
        }
    }
    skip_spaces(&p);
    if (*p != '\0') return 0;
    record->year = values[0];
    record->month = values[1];
    record->day = values[2];
    record->hour = values[3];
    record->minute = values[4];
    record->temperature = values[5];
    return valid_record(*record);
}

/* 1 — строка прочитана, 0 — конец файла, -1 — слишком длинная строка,
   -2 — нулевой байт внутри строки, -3 — ошибка чтения.
   Даже ошибочная строка считывается целиком до перевода строки/конца файла. */
int read_csv_line(FILE *file, char line[], int capacity)
{
    int ch, length = 0, too_long = 0, zero_byte = 0, seen = 0;
    while ((ch = fgetc(file)) != EOF) {
        seen = 1;
        if (ch == '\n') break;
        if (ch == 0) zero_byte = 1;
        if (length < capacity - 1)
            line[length++] = (char)ch;
        else
            too_long = 1;
    }
    line[length] = '\0';
    if (ferror(file)) return -3;
    if (!seen) return 0;
    if (zero_byte) return -2;
    if (too_long) return -1;
    /* Убираем только завершающий CR из CRLF, а не произвольный хвост строки. */
    if (length > 0 && line[length - 1] == '\r') line[length - 1] = '\0';
    return 1;
}

int report_csv_error(FILE *stream, unsigned long line_no, const char *reason)
{
    return fprintf(stream, "Строка %lu: %s; запись пропущена.\n", line_no, reason) >= 0;
}

/* Сохранён интерфейс предыдущего этапа для обычной загрузки. */
int load_csv(TemperatureArray *array, const char *filename)
{
    return load_csv_with_log(array, filename, NULL);
}

int load_csv_with_log(TemperatureArray *array, const char *filename, const char *error_filename)
{
    FILE *file = fopen(filename, "r");
    FILE *errors = stderr;
    char line[256];
    int status, loaded = 0, success = 1;
    unsigned long line_no = 0, skipped = 0;
    if (file == NULL) { perror(filename); return 0; }
    if (error_filename != NULL) {
        /* Режим C11 "wx": создать только новый файл.
           Существующий файл (включая исходный CSV) не перезаписывается. */
        errors = fopen(error_filename, "wx");
        if (errors == NULL) { perror(error_filename); fclose(file); return 0; }
    }
    while ((status = read_csv_line(file, line, (int)sizeof(line))) != 0) {
        const char *p = line;
        const char *reason = NULL;
        TemperatureRecord record;
        if (status == -3) {
            fputs("Ошибка чтения CSV.\n", stderr);
            success = 0;
            break;
        }
        line_no++;
        if (status == -1) reason = "слишком длинная строка";
        else if (status == -2) reason = "нулевой байт внутри текстовой строки";
        else {
            /* Допускается UTF-8 BOM только в начале файла. */
            if (line_no == 1 && strlen(line) >= 3 &&
                (unsigned char)line[0] == 0xef &&
                (unsigned char)line[1] == 0xbb &&
                (unsigned char)line[2] == 0xbf)
                p += 3;
            skip_spaces(&p);
            if (*p == '\0') continue;
            if (line_no == 1 &&
                (strcmp(p, "year;month;day;hour;minute;temperature") == 0 ||
                 strcmp(p, "YEAR;MONTH;DAY;HOUR;MINUTE;TEMPERATURE") == 0))
                continue;
            if (!parse_record(p, ';', &record))
                reason = "неверный формат, дата, время или температура";
            else if (array->size > 0 && record.year != array->data[0].year)
                reason = "другой год";
        }
        if (reason != NULL) {
            skipped++;
            if (!report_csv_error(errors, line_no, reason)) {
                fputs("Не удалось записать сообщение об ошибке CSV.\n", stderr);
                success = 0;
                break;
            }
            continue;
        }
        if (!add_record(array, record)) {
            fprintf(stderr, "Не удалось расширить массив: недостаточно памяти или достигнут предел размера; строка %lu.\n", line_no);
            success = 0;
            break;
        }
        loaded++;
    }
    fclose(file);
    if (errors != stderr && fclose(errors) != 0) {
        fputs("Ошибка сохранения журнала CSV.\n", stderr);
        success = 0;
    }
    if (skipped > 0) {
        fprintf(stderr, "Пропущено записей: %lu.\n", skipped);
        if (error_filename != NULL)
            fprintf(stderr, "Номера строк и причины: %s\n", error_filename);
    }
    if (!success) return 0;
    if (loaded == 0) { fputs("Нет корректных записей для загрузки.\n", stderr); return 0; }
    return 1;
}

int save_csv(const TemperatureArray *array, const char *filename)
{
    FILE *file = fopen(filename, "w");
    int i;
    if (file == NULL) { perror(filename); return 0; }
    if (fprintf(file, "year;month;day;hour;minute;temperature\n") < 0) {
        fclose(file); return 0;
    }
    for (i = 0; i < array->size; i++) {
        TemperatureRecord r = array->data[i];
        if (fprintf(file, "%04d;%02d;%02d;%02d;%02d;%d\n",
                    r.year, r.month, r.day, r.hour, r.minute, r.temperature) < 0) {
            fclose(file); return 0;
        }
    }
    return fclose(file) == 0;
}

void print_help(const char *program)
{
    printf("Статистика температуры. Запуск: %s -f FILE [-m MONTH] [-e LOG] [-i]\n", program);
    puts("  -h        Описание программы и ключей");
    puts("  -f FILE   Входной CSV с разделителем ; (один год)");
    puts("  -m MONTH  Только статистика указанного месяца: 1..12");
    puts("  -e LOG    Создать новый журнал всех ошибочных строк; на экране — сводка");
    puts("  -i        Меню добавления, удаления, сортировки, печати и сохранения");
    puts("Без -m выводятся все месяцы и статистика за год.");
    puts("CSV: YEAR;MONTH;DAY;HOUR;MINUTE;TEMPERATURE (разделитель ;)");
    puts("Заголовок необязателен; пробелы и ведущие нули в числах допускаются.");
    puts("Ошибочные записи пропускаются с номером строки.");
    puts("Пункт сохранения в меню перезаписывает входной файл.");
    puts("Динамический массив: вместимость увеличивается по мере добавления записей.");
}

int parse_options(int argc, char *argv[], ProgramOptions *options)
{
    int i;
    options->filename = NULL;
    options->error_filename = NULL;
    options->month = 0;
    options->interactive = 0;
    options->help = argc == 1;
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            options->help = 1;
            return 1;
        } else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) {
            options->filename = argv[++i];
        } else if (strcmp(argv[i], "-e") == 0 && i + 1 < argc) {
            options->error_filename = argv[++i];
        } else if (strcmp(argv[i], "-m") == 0 && i + 1 < argc) {
            const char *p = argv[++i];
            if (!parse_number(&p, 1, 12, &options->month) || *p != '\0') {
                fputs("Номер месяца должен быть целым числом от 1 до 12.\n", stderr);
                return 0;
            }
        } else if (strcmp(argv[i], "-i") == 0) {
            options->interactive = 1;
        } else {
            fprintf(stderr, "Неизвестный ключ или отсутствует значение: %s\n", argv[i]);
            return 0;
        }
    }
    if (!options->help && options->filename == NULL) {
        fputs("Укажите входной файл с помощью -f.\n", stderr);
        return 0;
    }
    return 1;
}

void print_statistics(const TemperatureArray *array, int month)
{
    int year, m, first, last;
    if (array->size == 0) { puts("Нет измерений."); return; }
    year = array->data[0].year;
    printf("Год: %d. Записей: %d.\n", year, array->size);
    first = month == 0 ? 1 : month;
    last = month == 0 ? 12 : month;
    for (m = first; m <= last; m++) {
        printf("\nМесяц %02d:\n", m);
        print_month_average(array->data, array->size, year, m);
        print_month_min(array->data, array->size, year, m);
        print_month_max(array->data, array->size, year, m);
    }
    if (month == 0) {
        printf("\nСтатистика за %d год:\n", year);
        print_year_average(array->data, array->size, year);
        print_year_min(array->data, array->size, year);
        print_year_max(array->data, array->size, year);
    }
}

void discard_line(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) { }
}

/* 1 — успех, 0 — ошибка ввода, -1 — конец ввода. */
int read_integer(const char *message, int minimum, int maximum, int *value)
{
    char line[128];
    const char *p = line;
    printf("%s", message);
    if (fgets(line, sizeof(line), stdin) == NULL) return -1;
    if (strchr(line, '\n') == NULL && !feof(stdin)) {
        discard_line(); return 0;
    }
    if (!parse_number(&p, minimum, maximum, value)) return 0;
    skip_spaces(&p);
    return *p == '\0';
}

void edit_menu(TemperatureArray *array, const char *filename, int month)
{
    int choice, index, status;
    for (;;) {
        puts("\n1 Добавить  2 Удалить  3 Сортировать  4 Печать  5 Сохранить CSV  6 Статистика  0 Выход");
        status = read_integer("Выбор: ", 0, 6, &choice);
        if (status < 0) return;
        if (!status) { puts("Введите номер пункта от 0 до 6."); continue; }
        if (choice == 0) return;
        if (choice == 1) {
            char line[256];
            TemperatureRecord record;
            puts("Введите через пробел: год месяц день час минута температура");
            if (fgets(line, sizeof(line), stdin) == NULL) return;
            if (strchr(line, '\n') == NULL && !feof(stdin)) {
                discard_line(); puts("Слишком длинная запись."); continue;
            }
            if (!parse_record(line, ' ', &record)) puts("Некорректная запись.");
            else if (array->size > 0 && record.year != array->data[0].year)
                puts("Год записи должен совпадать с годом массива.");
            else if (!add_record(array, record))
                puts("Не удалось расширить массив: недостаточно памяти или достигнут предел размера.");
            else puts("Запись добавлена.");
        } else if (choice == 2) {
            if (array->size == 0) { puts("Массив пуст."); continue; }
            status = read_integer("Номер записи (с 1): ", 1, array->size, &index);
            if (status < 0) return;
            if (!status || !delete_record(array, index - 1)) puts("Неверный номер записи.");
            else puts("Запись удалена.");
        } else if (choice == 3) {
            sort_array(array); puts("Массив отсортирован по дате и времени.");
        } else if (choice == 4) {
            print_array(array);
        } else if (choice == 5) {
            puts(save_csv(array, filename) ? "CSV сохранён." : "Ошибка сохранения.");
        } else if (choice == 6) {
            print_statistics(array, month);
        }
    }
}
