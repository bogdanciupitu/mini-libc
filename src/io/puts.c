#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int puts(const char *str)
{
    int length = strlen(str);

    if (write(1, str, length) != length) {
        return -1;
    }
    if (write(1, "\n", 1) != 1) {
        return -1;
    }

    return 0;
}
