#include "users.h"
#include <stdio.h>
#include <pwd.h>
#include <stdlib.h>

void list_users() {
    struct passwd *pw;
    printf("Users:\n");

    while ((pw = getpwent()) != NULL) {
        printf("%s - %s\n", pw->pw_name, pw->pw_dir);
    }

    endpwent();
}
