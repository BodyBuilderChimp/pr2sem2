#include <stdio.h>

void print_help() {
    printf("Usage: console_tool [OPTIONS]\n");
    printf("Options:\n");
    printf("  -u, --users         Show list of users and their home directories\n");
    printf("  -p, --processes     Show list of running processes\n");
    printf("  -h, --help          Display this help message\n");
    printf("  -l PATH, --log PATH Redirect output to file\n");
    printf("  -e PATH, --errors PATH Redirect stderr to file\n");
}