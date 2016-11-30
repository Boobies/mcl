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

#include <exceptions.h>
#if __STDC_VERSION__ >= 201112L && !defined(__STDC_NO_THREADS__)
    #include <threads.h>
#else
    #define thread_local
#endif

thread_local struct mcl_exceptionframe *mcl_exceptionstack;

