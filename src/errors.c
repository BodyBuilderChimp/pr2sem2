#include "errors.h"
#include <stdio.h>
#include <stdlib.h>

int redirect_stderr(const char *path) {
    FILE *file = freopen(path, "w", stderr);
    return (file == NULL) ? -1 : 0;
}
