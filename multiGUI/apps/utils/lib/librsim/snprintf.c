/* This file is part of the RSIM Applications Library and was modified
from the GNU C library as follows:

Separate initialization calls for stdio streams
Testing against the UNIX stdio streams to determine if the user
is using those structures instead. */  
/* Copyright (C) 1991 Free Software Foundation, Inc.
This file is part of the GNU C Library.

The GNU C Library is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public License as
published by the Free Software Foundation; either version 2 of the
License, or (at your option) any later version.

The GNU C Library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Library General Public License for more details.

You should have received a copy of the GNU Library General Public
License along with the GNU C Library; see the file COPYING.LIB.  If
not, write to the Free Software Foundation, Inc., 675 Mass Ave,
Cambridge, MA 02139, USA.  */

#include <ansidecl.h>
#include <stdarg.h>
#include <stdio.h>


/* Write formatted output into S, according to the format
   string FORMAT, writing no more than MAXLEN characters.  */
/* VARARGS3 */
int
DEFUN(snprintf, (s, maxlen, format),
      char *s AND size_t maxlen AND CONST char *format DOTS)
{
  va_list arg;
  int done;

  va_start(arg, format);
  done = vsnprintf(s, maxlen, format, arg);
  va_end(arg);

  return done;
}
