// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	int result = syscall(8, fd, offset, whence);

	if (result < 0) {
		errno = -result;
		return -1;
	}

	return result;
}
