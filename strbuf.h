/*
 * strbuf.c: A simple string buffer
 *
 * Copyright (c) 2006 Dennis Stosberg <dennis@stosberg.net>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License,
 * version 2 as published by the Free Software Foundation
 */

#ifndef STRBUF_H
#define STRBUF_H

#include "mem.h"

typedef struct strbuf {
	char *data;
	size_t len;
	size_t buf_sz;
} STRBUF;

/*
 * Initialize a new string buffer.  There is currently no other way to
 * get a new one.
 */
STRBUF *strbuf_new();

/*
 * Free a string buffer
 */
void strbuf_free(STRBUF *buf);

/*
 * Appends the n first characters from str to the string buffer
 *
 * Returns the new length of the string buffer.
 */
size_t strbuf_append_n(STRBUF *buf, const char *str, size_t n);

/*
 * Appends str to the strin buffer
 *
 * Returns the new length of the string buffer
 */
size_t strbuf_append(STRBUF *buf, const char *str);

/*
 * Returns a pointer to the contained string
 */
const char *strbuf_get(STRBUF *buf);

/*
 * Returns the length of the contained string
 */
size_t strbuf_len(STRBUF *buf);

/*
 * Reallocs the data structure in the string buffer to use not more
 * memory than necessary.
 */
void strbuf_shrink(STRBUF *buf);

/*
 * Creates a string buffer from a *char without copying
 */
STRBUF *strbuf_create_slurp(char *str);
STRBUF *strbuf_create_slurp_n(char *str, size_t len);

/*
 * Returns the contained string and destroys the string buffer
 */
char *strbuf_spit(STRBUF *buf);

/*
 * Substitute characters in the string buffer buf from start
 * (inclusive) to end (exclusive) and replace them with *subst. The
 * first character in the string has the index 0.
 *
 * Returns the change of the length of the string contained at *buf.
 * The return value is negative, if the string is shortened, zero if
 * the length is unchanged and positive if the length increases.
 *
 * If start is bigger than stop, their values are automatically
 * swapped.
 */
int strbuf_subst(STRBUF *buf, size_t start, size_t stop,
	      const char *subst);

#endif /* STRBUF_H */