// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	char *p = destination;

	while ((*p = *source) != '\0') {
		p++;
		source++;
	}

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	char *p = destination;

	while (len && (*p++ = *source++)) {
		len--;
	}

	while (len--) {
		*p++ = '\0';
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	char *p = destination;

	while (*p) {
		p++;
	}

	while ((*p = *source) != '\0') {
		p++;
		source++;
	}

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	char *p = destination;

	while (*p) {
		p++;
	}

	while (len > 0 && *source != '\0') {
		*p = *source;
		p++;
		source++;
		len--;
	}

	*p = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	while (*str1 == *str2) {
		if (*str1 == '\0') {
			return 0;
		}
		str1++;
		str2++;
	}

	if ((char)*str1 > (char)*str2) {
		return 1;
	}
	return -1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	while (len > 0) {
		if (*str1 != *str2) {
			if ((unsigned char)*str1 < (unsigned char)*str2) {
				return -1;
			}
			return 1;
		}
		if (*str1 == '\0') {
			return 0;
		}
		str1++;
		str2++;
		len--;
	}

	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	while (*str != '\0') {
		if (*str == (char)c) {
			return (char *)str;
		}
		str++;
	}

	if (*str == (char)c) {
		return (char *)str;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	char *last = NULL;

	while (*str) {
		if (*str == (char)c) {
			last = str;
		}
		str++;
	}

	return (char *)last;
}

char *strstr(const char *haystack, const char *needle)
{
	if (!*needle) {
		return (char *)haystack;
	}

	while (*haystack) {
		if ((*haystack == *needle) && !strncmp(haystack, needle, strlen(needle))) {
			return (char *)haystack;
		}
		haystack++;
	}

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	char *last = NULL;

	if (!*needle) {
		return (char *)haystack;
	}

	while (*haystack) {
		if ((*haystack == *needle) && !strncmp(haystack, needle, strlen(needle))) {
			last = (char *)haystack;
		}
		haystack++;
	}

	return last;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *p = (char *)destination;
	char *q = (char *)source;

	while (num) {
		*p++ = *q++;
		num--;
	}

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *p = (char *)destination;
	char *q = (char *)source;

	if (p < q) {
		while (num) {
			*p++ = *q++;
			num--;
		}
	} else {
		p += num;
		q += num;
		while (num) {
			num--;
			p--;
			q--;
			*p = *q;
		}
	}

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	char *p = (char *)ptr1;
	char *q = (char *)ptr2;

	while (num) {
		if (*p != *q) {
			if (*p < *q) {
				return -1;
			}
			return 1;
		}
		p++;
		q++;
		num--;
	}

	return 0;
}

void *memset(void *source, int value, size_t num)
{
	char *p = (char *)source;

	while (num) {
		*p = (char)value;
		p++;
		num--;
	}

	return source;
}
