#include "temp_functions.h"

int main(int argc, char *argv[])
{
    TemperatureArray array; /* Небольшой контейнер; сами записи хранятся в куче. */
    ProgramOptions options;

    if (!parse_options(argc, argv, &options))
        return 1;
    if (options.help) {
        print_help(argv[0]);
        return 0;
    }

    create_array(&array);
    if (!load_csv_with_log(&array, options.filename, options.error_filename)) {
        free_array(&array); /* Освободить и частично загруженные данные. */
        return 1;
    }
    print_statistics(&array, options.month);
    if (options.interactive)
        edit_menu(&array, options.filename, options.month);

    free_array(&array);
    return 0;
}
