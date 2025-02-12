#ifndef __TIME_H__
#define __TIME_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

typedef long time_t;

struct timespec {
    time_t tv_sec;
    long   tv_nsec;
};

int nanosleep(const struct timespec *req, struct timespec *rem);
unsigned int sleep(unsigned int seconds);

#ifdef __cplusplus
}
#endif

#endif
