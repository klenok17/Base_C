#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

#include <stdio.h> /* FILE в прототипах функций чтения и журнала. */

/* Тип и поля сохранены из задания 11. */
typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;
} TemperatureRecord;

typedef struct {
    TemperatureRecord *data; /* Буфер в динамической памяти. */
    int size;               /* Число заполненных элементов. */
    int capacity;           /* Число элементов, для которых выделено место. */
} TemperatureArray;

typedef struct {
    const char *filename;
    const char *error_filename; /* NULL — сообщения в stderr. */
    int month;       /* 0 — все месяцы и год. */
    int interactive;
    int help;
} ProgramOptions;

/* Имена и параметры всех шести функций сохранены из задания 11. */
void print_month_average(const TemperatureRecord data[], int count, int year, int month);
void print_month_min(const TemperatureRecord data[], int count, int year, int month);
void print_month_max(const TemperatureRecord data[], int count, int year, int month);
void print_year_average(const TemperatureRecord data[], int count, int year);
void print_year_min(const TemperatureRecord data[], int count, int year);
void print_year_max(const TemperatureRecord data[], int count, int year);

void create_array(TemperatureArray *array);
void free_array(TemperatureArray *array);
int grow_array(TemperatureArray *array);
int valid_record(TemperatureRecord record);
int add_record(TemperatureArray *array, TemperatureRecord record);
int delete_record(TemperatureArray *array, int index);
int compare_dates(const void *left, const void *right);
void sort_array(TemperatureArray *array);
void print_array(const TemperatureArray *array);
int load_csv(TemperatureArray *array, const char *filename);
int load_csv_with_log(TemperatureArray *array, const char *filename, const char *error_filename);
int read_csv_line(FILE *file, char line[], int capacity);
int report_csv_error(FILE *stream, unsigned long line_no, const char *reason);
int save_csv(const TemperatureArray *array, const char *filename);

/* Вспомогательные функции тоже объявлены здесь согласно схеме задания. */
void skip_spaces(const char **text);
int parse_number(const char **text, int minimum, int maximum, int *value);
int parse_record(const char *text, char separator, TemperatureRecord *record);
int read_integer(const char *message, int minimum, int maximum, int *value);
void discard_line(void);
void print_help(const char *program);
int parse_options(int argc, char *argv[], ProgramOptions *options);
void print_statistics(const TemperatureArray *array, int month);
void edit_menu(TemperatureArray *array, const char *filename, int month);

#endif
