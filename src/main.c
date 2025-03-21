#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include "users.h"
#include "processes.h"
#include "logger.h"
#include "errors.h"
#include "help.h"

int main(int argc, char *argv[]) {
    int opt;
    char *log_path = NULL;
    char *error_path = NULL;
    
    int should_list_users = 0;    // Флаг для отображения пользователей
    int should_list_processes = 0; // Флаг для отображения процессов

    struct option long_options[] = {
        {"users", no_argument, NULL, 'u'},
        {"processes", no_argument, NULL, 'p'},
        {"help", no_argument, NULL, 'h'},
        {"log", required_argument, NULL, 'l'},
        {"error", required_argument, NULL, 'e'},
        {NULL, 0, NULL, 0}
    };

    // Проверяем, если нет аргументов
    if (argc < 2) {
        print_help();  // Выводим помощь, если опции не переданы
        return 0;
    }

    while (1) {
        int option_index = 0;
        opt = getopt_long(argc, argv, "uph:l:e:", long_options, &option_index);

        if (opt == -1) {
            break;
        }

        switch (opt) {
            case 'u':
                should_list_users = 1; // Отмечаем, что нужно отобразить пользователей
                break;
            case 'p':
                should_list_processes = 1; // Отмечаем, что нужно отобразить процессы
                break;
            case 'h':
                print_help(); // Выводим справку
                return 0;
            case 'l':
                log_path = optarg;
                if (redirect_stdout(log_path) != 0) {
                    fprintf(stderr, "Error: Cannot open log file %s\n", log_path);
                    return 1;
                }
                break;
            case 'e':
                error_path = optarg;
                if (redirect_stderr(error_path) != 0) {
                    fprintf(stderr, "Error: Cannot open error file %s\n", error_path);
                    return 1;
                }
                break;
            default:
                print_help(); // Выводим помощь при ошибке
                return 1;
        }
    }

    // Выполняем действия в зависимости от установленных флагов
    if (should_list_users) {
        list_users();
    }
    if (should_list_processes) {
        list_processes();
    }

    return 0;
}
