#include <stdio.h>
#include <stdint.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include "temp_api.h"

int main(void)
{
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif
    /* Массив структур с примерами измерений  */
    TemperatureRecord measurements[] = {
        {2026, 1,  5,  8, 30, -12},
        {2026, 1, 15, 14, 10,  -5},
        {2026, 2,  3,  9,  0,  -8},
        {2026, 2, 20, 17, 45,   2},
        {2026, 3, 10, 12,  0,   7},
        {2026, 7, 21, 15, 20,  28}
    };
    int count = (int)(sizeof(measurements) / sizeof(measurements[0]));
    int i;
    int month;
    int year = 2026;

    printf("Зарегистрированные измерения:\n");
    for (i = 0; i < count; i++) {
        printf("%04d-%02d-%02d %02d:%02d  %d C\n",
               measurements[i].year,
               measurements[i].month,
               measurements[i].day,
               measurements[i].hour,
               measurements[i].minute,
               measurements[i].temperature);
    }

    printf("\nСтатистика по месяцам за %d год:\n", year);
    for (month = 1; month <= 12; month++) {
        printf("\nМесяц %02d:\n", month);
        print_month_average(measurements, count, year, month);
        print_month_min(measurements, count, year, month);
        print_month_max(measurements, count, year, month);
    }

    printf("\nСтатистика за %d год:\n", year);
    print_year_average(measurements, count, year);
    print_year_min(measurements, count, year);
    print_year_max(measurements, count, year);

    return 0;
}
