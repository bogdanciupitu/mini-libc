// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	if (length == 0) {
		errno = 22;
		return MAP_FAILED;
	}

	if (!(flags & 0x20) && fd < 0) {
		errno = 9;
		return MAP_FAILED;
	}

	long result = syscall(9, addr, length, prot, flags, fd, offset);

	if (result < 0) {
		errno = -result;
		return MAP_FAILED;
	}

	return (void *)result;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	if (!old_address || !old_size || !new_size) {
		errno = 22;
		return MAP_FAILED;
	}

	long result = syscall(25, old_address, old_size, new_size, flags);

	if (result < 0) {
		errno = -result;
		return MAP_FAILED;
	}

	return (void *)result;
}

int munmap(void *addr, size_t length)
{
	if (length == 0) {
		errno = 22;
		return -1;
	}

	int result = syscall(11, addr, length);

	if (result < 0) {
		return -1;
	}

	return 0;
}
