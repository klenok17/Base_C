#include <stdio.h>
#include "temp_api.h"

/* Пока только заглушки */
void print_month_average(const TemperatureRecord data[], int count, int year, int month)
{
    (void)data;
    (void)count;
    (void)year;
    (void)month;
    printf("  Среднемесячная температура: не вычислена (заглушка)\n");
}

void print_month_min(const TemperatureRecord data[], int count, int year, int month)
{
    (void)data;
    (void)count;
    (void)year;
    (void)month;
    printf("  Минимальная температура:   не вычислена (заглушка)\n");
}

void print_month_max(const TemperatureRecord data[], int count, int year, int month)
{
    (void)data;
    (void)count;
    (void)year;
    (void)month;
    printf("  Максимальная температура:  не вычислена (заглушка)\n");
}

void print_year_average(const TemperatureRecord data[], int count, int year)
{
    (void)data;
    (void)count;
    (void)year;
    printf("  Среднегодовая температура: не вычислена (заглушка)\n");
}

void print_year_min(const TemperatureRecord data[], int count, int year)
{
    (void)data;
    (void)count;
    (void)year;
    printf("  Минимальная температура:   не вычислена (заглушка)\n");
}

void print_year_max(const TemperatureRecord data[], int count, int year)
{
    (void)data;
    (void)count;
    (void)year;
    printf("  Максимальная температура:  не вычислена (заглушка)\n");
}
