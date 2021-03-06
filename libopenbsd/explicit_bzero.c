/*	$OpenBSD: explicit_bzero.c,v 1.2 2014/06/10 04:17:37 deraadt Exp $ */
/*
 * Public domain.
 * Written by Matthew Dempsky.
 */

#include "config.h"

#include <string.h>

#define __UNUSED __attribute__ ((unused))

__attribute__((weak)) void
__explicit_bzero_hook(__UNUSED void *buf, __UNUSED size_t len)
{
}

void
explicit_bzero(void *buf, size_t len)
{
	memset(buf, 0, len);
	__explicit_bzero_hook(buf, len);
}
