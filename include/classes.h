/*
 * Copyright 2016 Bogdan Barbu
 *
 * This file is part of the Modern C Library.
 *
 * The Modern C Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * The Modern C Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with the Modern C Library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MCL_CLASSES_H
#define MCL_CLASSES_H

#include <exceptions.h>
#include <stdarg.h>
#include <stddef.h>

extern const int bad_alloc;

typedef struct {
    size_t size;
    void *this;
    void (*ctor)(void *, va_list);
    void (*dtor)(void *);
} class;

extern void *new(const class *, ...);
extern void delete(void *);

#endif

