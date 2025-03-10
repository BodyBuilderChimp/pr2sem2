#include "processes.h"
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <ctype.h>

void list_processes() {
    DIR *dir = opendir("/proc");
    struct dirent *entry;

    if (!dir) {
        perror("Cannot open /proc");
        return;
    }

    printf("Processes:\n");
    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(entry->d_name[0])) {
            printf("PID: %s\n", entry->d_name);
        }
    }

    closedir(dir);
}
