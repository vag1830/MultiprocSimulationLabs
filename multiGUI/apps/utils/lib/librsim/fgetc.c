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
#include <errno.h>
#include <stdio.h>


/* Read a character from STREAM.  */
int
DEFUN(fgetc, (stream), FILE *stream)
{
  if (!__stdio_inited) __init_stdio();
  if (stream == (FILE *)(&__iob[0]))
    stream = stdin;
  else if (stream == (FILE *)(&__iob[1]))
    stream = stdout;
  else if (stream == (FILE *)(&__iob[2]))
    stream = stderr;
  
  if (!__validfp(stream) || !stream->__mode.__read)
    {
      errno = EINVAL;
      return EOF;
    }

  return __getc(stream);
}
