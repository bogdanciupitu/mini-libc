#include <time.h>
#include <errno.h>

unsigned int sleep(unsigned int seconds)
{
    struct timespec request = {
        .tv_sec = seconds,
        .tv_nsec = 0
    };
    struct timespec remaining;

    if (nanosleep(&request, &remaining) < 0) {
        return remaining.tv_sec;
    }

    return 0;
}
