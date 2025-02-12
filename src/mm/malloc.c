// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	if (size == 0) {
		return NULL;
	}

	void *p = mmap(NULL, size, 0x1 | 0x2, 0x02 | 0x20, -1, 0);

	if (p == MAP_FAILED) {
		return NULL;
	}

	mem_list_add(p, size);

	return p;
}

void *calloc(size_t nmemb, size_t size)
{
	void *p = malloc(nmemb * size);

	memset(p, 0, nmemb * size);

	return p;
}

void free(void *ptr)
{
	if (ptr == NULL) {
		return;
	}

	struct mem_list *elem = mem_list_find(ptr);
	if (elem) {
		munmap(ptr, elem->len);
		mem_list_del(ptr);
	}
}

void *realloc(void *ptr, size_t size)
{
	if (ptr == NULL) {
		return malloc(size);
	}

	if (size == 0){
		free(ptr);
		return NULL;
	}

	struct mem_list *elem = mem_list_find(ptr);
	if (!elem) {
		return NULL;
	}

	void *p = malloc(size);

	if (elem->len < size) {
		memcpy(p, ptr, elem->len);
	} else {
		memcpy(p, ptr, size);
	}

	mem_list_del(ptr);
	free(ptr);
	mem_list_add(p, size);

	return p;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	return realloc(ptr, nmemb * size);
}
