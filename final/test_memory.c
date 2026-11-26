/* Независимая проверка, не входит в prog и не нужна для выполнения ДЗ.
   GNU ld --wrap позволяет намеренно отказать в realloc(), не изменяя приложение.
   Здесь же учитываются выделенные приложением буферы и вызовы free(). */
#include "temp_functions.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void *__real_realloc(void *pointer, size_t size);
void __real_free(void *pointer);
void *__wrap_realloc(void *pointer, size_t size);
void __wrap_free(void *pointer);
int temperature_main(int argc, char *argv[]);

static int allocation_calls;
static int fail_on;
static int live_blocks;
static int released_blocks;

void *__wrap_realloc(void *pointer, size_t size)
{
    int first_allocation = pointer == NULL;
    void *result;
    allocation_calls++;
    if (allocation_calls == fail_on)
        return NULL;
    result = __real_realloc(pointer, size);
    if (result != NULL && first_allocation)
        live_blocks++;
    return result;
}

void __wrap_free(void *pointer)
{
    if (pointer != NULL) {
        live_blocks--;
        released_blocks++;
    }
    __real_free(pointer);
}

int main(int argc, char *argv[])
{
    TemperatureArray a;
    TemperatureRecord r = {2026, 1, 1, 0, 0, -99};
    TemperatureRecord mixed[] = {
        {2026, 1, 1, 0, 0, -10},
        {2026, 1, 2, 0, 0, -2},
        {2027, 1, 1, 0, 0, 99}
    };
    TemperatureRecord *old_data;
    int i, calls_before, freed_before;
    char *normal[] = {"prog", "-f", NULL, NULL};
    char *help[] = {"prog", "-h", NULL};
    char *bad_option[] = {"prog", "-m", "13", NULL};
    assert(argc == 3);

    create_array(&a);
    assert(a.data == NULL && a.size == 0 && a.capacity == 0);
    sort_array(&a);
    assert(!delete_record(&a, 0) && !delete_record(&a, -1));
    free_array(&a);
    free_array(&a);
    assert(live_blocks == 0);

    /* Отказ первого выделения: контейнер остаётся пустым. */
    fail_on = allocation_calls + 1;
    assert(!add_record(&a, r));
    assert(a.data == NULL && a.size == 0 && a.capacity == 0);
    fail_on = 0;

    for (i = 0; i < 8; i++) {
        r.day = 20 - i;
        assert(add_record(&a, r));
    }
    assert(a.size == 8 && a.capacity == 8 && live_blocks == 1);
    old_data = a.data;
    fail_on = allocation_calls + 1;
    assert(!add_record(&a, r));
    assert(a.data == old_data && a.size == 8 && a.capacity == 8);
    for (i = 0; i < 8; i++)
        assert(a.data[i].day == 20 - i && a.data[i].temperature == -99);
    fail_on = 0;

    for (i = 8; i < 20; i++) {
        r.day = 20 - i;
        assert(add_record(&a, r));
    }
    assert(a.size == 20 && a.capacity == 32 && live_blocks == 1);
    sort_array(&a);
    assert(a.data[0].day == 1 && a.data[19].day == 20);
    assert(delete_record(&a, 10));
    assert(a.size == 19 && a.data[10].day == 12 && a.capacity == 32);
    assert(!delete_record(&a, a.size));
    r.year = 2027;
    assert(!add_record(&a, r));
    r.year = 2026; r.temperature = -100;
    assert(!add_record(&a, r));
    r.temperature = 100;
    assert(!add_record(&a, r));
    r.temperature = 99;
    assert(add_record(&a, r));
    r.temperature = 0; r.month = 2; r.day = 29;
    r.year = 1900; assert(!valid_record(r));
    r.year = 2000; assert(valid_record(r));
    while (a.size > 0) assert(delete_record(&a, 0));
    assert(a.capacity == 32 && a.data != NULL);
    sort_array(&a);
    free_array(&a);
    assert(a.data == NULL && a.size == 0 && a.capacity == 0 && live_blocks == 0);

    /* Проверка ветви ограничения размера без создания огромного буфера.
       Этот искусственный контейнер используется только для grow_array(). */
    a.capacity = INT_MAX;
    calls_before = allocation_calls;
    assert(!grow_array(&a) && allocation_calls == calls_before);
    create_array(&a);

    print_month_average(mixed, 3, 2026, 1);
    print_month_min(mixed, 3, 2026, 1);
    print_month_max(mixed, 3, 2026, 1);
    print_year_average(mixed, 3, 2026);
    print_year_min(mixed, 3, 2026);
    print_year_max(mixed, 3, 2026);

    /* Проверяем реальные пути main(): ошибка до выделения памяти,
       отказ первого выделения, отказ расширения, нормальное завершение. */
    calls_before = allocation_calls;
    assert(temperature_main(2, help) == 0);
    assert(temperature_main(3, bad_option) == 1);
    normal[2] = argv[2];
    assert(temperature_main(3, normal) == 1);
    assert(allocation_calls == calls_before && live_blocks == 0);

    normal[2] = argv[1];
    fail_on = allocation_calls + 1;
    assert(temperature_main(3, normal) == 1 && live_blocks == 0);
    freed_before = released_blocks;
    fail_on = allocation_calls + 2;
    assert(temperature_main(3, normal) == 1 && live_blocks == 0);
    assert(released_blocks == freed_before + 1);

    fail_on = 0;
    freed_before = released_blocks;
    assert(temperature_main(3, normal) == 0 && live_blocks == 0);
    assert(released_blocks == freed_before + 1);
    puts("MEMORY TESTS PASSED");
    return 0;
}
