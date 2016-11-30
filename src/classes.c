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

#include <classes.h>

const int bad_alloc = -1;

void *new(const class *const descriptor, ...) {
    void *object = malloc(descriptor->size);
    va_list args;

    if (object == NULL)
        throw(bad_alloc);

    *(class *)object = *descriptor;
    ((class *)object)->this = object;
    va_start(args, descriptor);
    ((class *)object)->ctor(((class *)object)->this, args);
    va_end(args);

    return object;
}

void delete(void *const object) {

    ((class *)object)->dtor(((class *)object)->this);
    free(object);
}

