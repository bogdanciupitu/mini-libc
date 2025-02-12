#include <time.h>
#include <internal/syscall.h>
#include <errno.h>

int nanosleep(const struct timespec *req, struct timespec *rem)
{
    int result = syscall(35, req, rem);

    if (result < 0) {
        errno = 4;
    }

    return result;
}
