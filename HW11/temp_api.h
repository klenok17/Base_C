#ifndef TEMP_API_H
#define TEMP_API_H
#include <stdint.h>

/* Одна запись о температуре с датой и временем измерения. */
typedef struct {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
} TemperatureRecord;

/* Заглушки: статистика за месяц. */
void print_month_average(const TemperatureRecord data[], int count, int year, int month);
void print_month_min(const TemperatureRecord data[], int count, int year, int month);
void print_month_max(const TemperatureRecord data[], int count, int year, int month);

/* Заглушки: статистика за год. */
void print_year_average(const TemperatureRecord data[], int count, int year);
void print_year_min(const TemperatureRecord data[], int count, int year);
void print_year_max(const TemperatureRecord data[], int count, int year);

#endif
