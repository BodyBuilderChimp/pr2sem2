#include "logger.h"
#include <stdio.h>
#include <stdlib.h>

int redirect_stdout(const char *path) {
    FILE *file = freopen(path, "w", stdout);
    return (file == NULL) ? -1 : 0;
}
