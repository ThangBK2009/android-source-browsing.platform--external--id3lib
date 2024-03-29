/*
** Copyright (C) 1988 Eleftherios Gkioulekas <lf@amath.washington.edu>
** Copyright (C) 2006 Andre Pang <ozone@algorithm.com.au>
**
** This file is free software; as a special exception the author gives
** unlimited permission to copy and/or distribute it, with or without
** modifications, as long as this notice is preserved.
**
** This program is distributed in the hope that it will be useful, but
** WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
** implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

/* This is the top section */

/* And now the rest of the boys */
/* #undef CXX_HAS_BUGGY_FOR_LOOPS */
/* the following is added due to a bug in autoconf, checking for booleans in gcc while g++ is used for compiling */
#ifndef __cplusplus
/* #undef CXX_HAS_NO_BOOL */
#endif
/* #undef ID3_ENABLE_DEBUG */
/* #undef ID3_DISABLE_ASSERT */
/* #undef ID3_DISABLE_CHECKS */
#define ID3_ICONV_FORMAT_UTF16BE "UTF-16BE"
#define ID3_ICONV_FORMAT_UTF16LE "UTF-16LE"
#define ID3_ICONV_FORMAT_UTF8 "UTF-8"
#define ID3_ICONV_FORMAT_ISO_8859_1 "ISO-8859-1"
#define ID3LIB_ICONV_OLDSTYLE 1
/* #undef ID3LIB_ICONV_CAST_OK */

/* config.h defines these preprocesser symbols to be used by id3lib for
 * determining internal versioning information.  The intent is that these
 * macros will be made available in the library via constants, functions,
 * or static methods.
 */
#define HAVE_ZLIB 1
#define HAVE_GETOPT_LONG 1
#define _ID3LIB_NAME "id3lib"
#define _ID3LIB_VERSION "3.8.3"
#define _ID3LIB_FULLNAME "id3lib-3.8.3"
#define _ID3LIB_MAJOR_VERSION 3
#define _ID3LIB_MINOR_VERSION 8
#define _ID3LIB_PATCH_VERSION 3
#define _ID3LIB_INTERFACE_AGE 0
#define _ID3LIB_BINARY_AGE 0
#define _ID3_COMPILED_WITH_DEBUGGING "minimum"
/* */


/* Define if you have the <cctype> header file. */
#define HAVE_CCTYPE 1

/* Define if you have the <climits> header file. */
#define HAVE_CLIMITS 1

/* Define if you have the <cstdio> header file. */
#define HAVE_CSTDIO 1

/* Define if you have the <cstdlib> header file. */
#define HAVE_CSTDLIB 1

/* Define if you have the <cstring> header file. */
#define HAVE_CSTRING 1

/* Define if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define if you have the <fstream> header file. */
#define HAVE_FSTREAM 1

/* Define if you have the <fstream.h> header file. */
/* #undef HAVE_FSTREAM_H */

/* Define if you have the `getopt_long' function. */
#define HAVE_GETOPT_LONG 1

/* Define if you have the <iconv.h> header file. */
#define HAVE_ICONV_H 1

/* Define if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define if you have the <iomanip> header file. */
#define HAVE_IOMANIP 1

/* Define if you have the <iomanip.h> header file. */
#define HAVE_IOMANIP_H 1

/* Define if you have the <iostream> header file. */
#define HAVE_IOSTREAM 1

/* Define if you have the <iostream.h> header file. */
/* #undef HAVE_IOSTREAM_H */

/* Define if you have the <libcw/sys.h> header file. */
/* #undef HAVE_LIBCW_SYS_H */

/* Define if you have the <bitset> header file. */
#define HAVE_BITSET 1

/* Define if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define if you have the `mkstemp' function. */
#define HAVE_MKSTEMP 1

/* Define if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define if you have the <string> header file. */
#define HAVE_STRING 1

/* Define if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define if you have the <sys/param.h> header file. */
#define HAVE_SYS_PARAM_H 1

/* Define if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define if you have the `truncate' function. */
#define HAVE_TRUNCATE 1

/* Define if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define if you have the <wchar.h> header file. */
#define HAVE_WCHAR_H 1

/* Define if you have the <zlib.h> header file. */
#define HAVE_ZLIB_H 1

/* Define to 1 if your processor stores words with the most significant byte
   first (like Motorola and SPARC, unlike Intel and VAX). */
#ifdef __APPLE__
	#ifdef __BIG_ENDIAN__
		#define WORDS_BIGENDIAN 1
	#else
		#undef WORDS_BIGENDIAN
	#endif
#else
	Error this config.h file is only valid for Mac OS. Run ./configure for other OSes 
#endif

/* Name of package */
#define PACKAGE "id3lib"

/* Define if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Version number of package */
#define VERSION "3.8.3"

/* Define if you need to in order for stat and other things to work. */
/* #undef _POSIX_SOURCE */

/* Define to `unsigned' if <sys/types.h> does not define. */
/* #undef size_t */
/* This is the bottom section */

// This file defines portability work-arounds for various proprietory
// C++ compilers

// Workaround for compilers with buggy for-loop scoping
// That's quite a few compilers actually including recent versions of
// Dec Alpha cxx, HP-UX CC and SGI CC.
// The trivial "if" statement provides the correct scoping to the
// for loop

#ifdef CXX_HAS_BUGGY_FOR_LOOPS
/* #undef for */
#define for if(1) for
#endif

//
// If the C++ compiler we use doesn't have bool, then
// the following is a near-perfect work-around.
// You must make sure your code does not depend on "int" and "bool"
// being two different types, in overloading for instance.
//

#ifdef CXX_HAS_NO_BOOL
#define bool int
#define true 1
#define false 0
#endif

#if defined (ID3_ENABLE_DEBUG) && defined (HAVE_LIBCW_SYS_H) && defined (__cplusplus)

#define DEBUG

#include <libcw/sys.h>
#include <libcw/debug.h>

#define ID3D_INIT_DOUT()    Debug( libcw_do.on() )
#define ID3D_INIT_WARNING() Debug( dc::warning.on() )
#define ID3D_INIT_NOTICE()  Debug( dc::notice.on() )
#define ID3D_NOTICE(x)      Dout( dc::notice, x )
#define ID3D_WARNING(x)     Dout( dc::warning, x )

#else

#  define ID3D_INIT_DOUT()
#  define ID3D_INIT_WARNING()
#  define ID3D_INIT_NOTICE()
#  define ID3D_NOTICE(x)
#  define ID3D_WARNING(x)

#endif /* defined (ID3_ENABLE_DEBUG) && defined (HAVE_LIBCW_SYS_H) */


