#ifndef LIBNPYMATH_COMMON_H_
#define LIBNPYMATH_COMMON_H_

/* need Python.h for Py_intptr_t */
#include <Python.h>

#include <limits.h>

/* numpconfig.h is auto-generated */
#include "libnpymath/config.h"
#include "libnpymath/block.h"

/*
 * using static inline modifiers when defining npy_math functions
 * allows the compiler to make optimizations when possible
 */
#ifndef NPYMATH_INLINE_MATH
#if defined(NPYMATH_INTERNAL_BUILD) && NPYMATH_INTERNAL_BUILD
    #define NPYMATH_INLINE_MATH 1
#else
    #define NPYMATH_INLINE_MATH 0
#endif
#endif

/*
 * give a hint to the compiler which branch is more likely or unlikely
 * to occur, e.g. rare error cases:
 *
 * if (NPYMATH_UNLIKELY(failure == 0))
 *    return NULL;
 *
 * the double !! is to cast the expression (e.g. NULL) to a boolean required by
 * the intrinsic
 */
#ifdef NPYMATH_HAVE___BUILTIN_EXPECT
#define NPYMATH_LIKELY(x) __builtin_expect(!!(x), 1)
#define NPYMATH_UNLIKELY(x) __builtin_expect(!!(x), 0)
#else
#define NPYMATH_LIKELY(x) (x)
#define NPYMATH_UNLIKELY(x) (x)
#endif

#ifndef Py_USING_UNICODE
#error Must use Python with unicode enabled.
#endif

/* Need to find the number of bits for each type and
        make definitions accordingly.

        C states that sizeof(char) == 1 by definition

        So, just using the sizeof keyword won't help.

        It also looks like Python itself uses sizeof(char) quite a
        bit, which by definition should be 1 all the time.

        Idea: Make Use of CHAR_BIT which should tell us how many
        BITS per CHARACTER
*/

/* Include platform definitions -- These are in the C89/90 standard */
#define NPYMATH_SIZEOF_BYTE 1

#define NPYMATH_BITSOF_CHAR CHAR_BIT
#define NPYMATH_BITSOF_BYTE (NPYMATH_SIZEOF_BYTE * CHAR_BIT)
#define NPYMATH_BITSOF_SHORT (NPYMATH_SIZEOF_SHORT * CHAR_BIT)
#define NPYMATH_BITSOF_INT (NPYMATH_SIZEOF_INT * CHAR_BIT)
#define NPYMATH_BITSOF_LONG (NPYMATH_SIZEOF_LONG * CHAR_BIT)
#define NPYMATH_BITSOF_LONGLONG (NPYMATH_SIZEOF_LONGLONG * CHAR_BIT)
#define NPYMATH_BITSOF_FLOAT (NPYMATH_SIZEOF_FLOAT * CHAR_BIT)
#define NPYMATH_BITSOF_DOUBLE (NPYMATH_SIZEOF_DOUBLE * CHAR_BIT)
#define NPYMATH_BITSOF_LONGDOUBLE (NPYMATH_SIZEOF_LONGDOUBLE * CHAR_BIT)

#ifdef NPYMATH_USE_NUMPY_TYPES

typedef npy_longlong npymath_longlong;
typedef npy_ulonglong npymath_ulonglong;

typedef npy_longdouble npymath_longdouble;

typedef npy_byte npymath_byte;
typedef npy_ubyte npymath_ubyte;
typedef npy_ushort npymath_ushort;
typedef npy_uint npymath_uint;
typedef npy_ulong npymath_ulong;

typedef npy_short npymath_short;
typedef npy_int npymath_int;
typedef npy_long npymath_long;
typedef npy_float npymath_float;
typedef npy_double npymath_double;

typedef npy_cdouble npymath_cdouble;
typedef npy_cfloat npymath_cfloat;
typedef npy_clongdouble npymath_clongdouble;

typedef npy_uint8 npymath_uint8;
typedef npy_int16 npymath_int16;
typedef npy_uint16 npymath_uint16;
typedef npy_int32 npymath_int32;
typedef npy_uint32 npymath_uint32;
typedef npy_int64 npymath_int64;
typedef npy_uint64 npymath_uint64;

#else /* !NPYMATH_USE_NUMPY_TYPES */

#ifdef PY_LONG_LONG
typedef PY_LONG_LONG npymath_longlong;
typedef unsigned PY_LONG_LONG npymath_ulonglong;
#else
typedef long npymath_longlong;
typedef unsigned long npymath_ulonglong;
#endif

/*
 * `NPYMATH_SIZEOF_LONGDOUBLE` isn't usually equal to sizeof(long double).
 * In some certain cases, it may forced to be equal to sizeof(double)
 * even against the compiler implementation and the same goes for
 * `complex long double`.
 *
 * Therefore, avoid `long double`, use `npymath_longdouble` instead,
 * and when it comes to standard math functions make sure of using
 * the double version when `NPYMATH_SIZEOF_LONGDOUBLE` == `NPYMATH_SIZEOF_DOUBLE`.
 * For example:
 *   npymath_longdouble *ptr, x;
 *   #if NPYMATH_SIZEOF_LONGDOUBLE == NPYMATH_SIZEOF_DOUBLE
 *       npymath_longdouble r = modf(x, ptr);
 *   #else
 *       npymath_longdouble r = modfl(x, ptr);
 *   #endif
 *
 * See https://github.com/numpy/numpy/issues/20348
 */
#if NPYMATH_SIZEOF_LONGDOUBLE == NPYMATH_SIZEOF_DOUBLE
    #define longdouble_t double
    typedef double npymath_longdouble;
#else
    #define longdouble_t long double
    typedef long double npymath_longdouble;
#endif

typedef signed char npymath_byte;
typedef unsigned char npymath_ubyte;
typedef unsigned short npymath_ushort;
typedef unsigned int npymath_uint;
typedef unsigned long npymath_ulong;

typedef short npymath_short;
typedef int npymath_int;
typedef long npymath_long;
typedef float npymath_float;
typedef double npymath_double;

#ifdef __cplusplus

typedef struct
{
    double _Val[2];
} npymath_cdouble;

typedef struct
{
    float _Val[2];
} npymath_cfloat;

typedef struct
{
    long double _Val[2];
} npymath_clongdouble;

#else /* !__cplusplus */

#include <complex.h>

#if defined(_MSC_VER) && !defined(__INTEL_COMPILER)
typedef _Dcomplex npymath_cdouble;
typedef _Fcomplex npymath_cfloat;
typedef _Lcomplex npymath_clongdouble;
#else /* !defined(_MSC_VER) || defined(__INTEL_COMPILER) */
typedef double _Complex npymath_cdouble;
typedef float _Complex npymath_cfloat;
typedef longdouble_t _Complex npymath_clongdouble;
#endif /* defined(_MSC_VER) && !defined(__INTEL_COMPILER) */

#endif /* __cplusplus */

#if NPYMATH_BITSOF_LONG == 8
#define NPYMATH_INT8
        typedef unsigned long npymath_uint8;
#elif NPYMATH_BITSOF_LONG == 16
#define NPYMATH_INT16
        typedef long npymath_int16;
        typedef unsigned long npymath_uint16;
#elif NPYMATH_BITSOF_LONG == 32
#define NPYMATH_INT32
        typedef long npymath_int32;
        typedef unsigned long npymath_uint32;
#elif NPYMATH_BITSOF_LONG == 64
#define NPYMATH_INT64
        typedef long npymath_int64;
        typedef unsigned long npymath_uint64;
#endif

#if NPYMATH_BITSOF_LONGLONG == 8
#  ifndef NPYMATH_INT8
#    define NPYMATH_INT8
        typedef npymath_ulonglong npymath_uint8;
#  endif
#elif NPYMATH_BITSOF_LONGLONG == 16
#  ifndef NPYMATH_INT16
#    define NPYMATH_INT16
        typedef npymath_longlong npymath_int16;
        typedef npymath_ulonglong npymath_uint16;
#  endif
#elif NPYMATH_BITSOF_LONGLONG == 32
#  ifndef NPYMATH_INT32
#    define NPYMATH_INT32
        typedef npymath_longlong npymath_int32;
        typedef npymath_ulonglong npymath_uint32;
#  endif
#elif NPYMATH_BITSOF_LONGLONG == 64
#  ifndef NPYMATH_INT64
#    define NPYMATH_INT64
        typedef npymath_longlong npymath_int64;
        typedef npymath_ulonglong npymath_uint64;
#  endif
#endif

#if NPYMATH_BITSOF_INT == 8
#ifndef NPYMATH_INT8
#define NPYMATH_INT8
        typedef unsigned int npymath_uint8;
#endif
#elif NPYMATH_BITSOF_INT == 16
#ifndef NPYMATH_INT16
#define NPYMATH_INT16
        typedef int npymath_int16;
        typedef unsigned int npymath_uint16;
#endif
#elif NPYMATH_BITSOF_INT == 32
#ifndef NPYMATH_INT32
#define NPYMATH_INT32
        typedef int npymath_int32;
        typedef unsigned int npymath_uint32;
#endif
#elif NPYMATH_BITSOF_INT == 64
#ifndef NPYMATH_INT64
#define NPYMATH_INT64
        typedef int npymath_int64;
        typedef unsigned int npymath_uint64;
#endif
#endif

#if NPYMATH_BITSOF_SHORT == 8
#ifndef NPYMATH_INT8
#define NPYMATH_INT8
        typedef unsigned short npymath_uint8;
#endif
#elif NPYMATH_BITSOF_SHORT == 16
#ifndef NPYMATH_INT16
#define NPYMATH_INT16
        typedef short npymath_int16;
        typedef unsigned short npymath_uint16;
#endif
#elif NPYMATH_BITSOF_SHORT == 32
#ifndef NPYMATH_INT32
#define NPYMATH_INT32
        typedef short npymath_int32;
        typedef unsigned short npymath_uint32;
#endif
#elif NPYMATH_BITSOF_SHORT == 64
#ifndef NPYMATH_INT64
#define NPYMATH_INT64
        typedef short npymath_int64;
        typedef unsigned short npymath_uint64;
#endif
#endif


#if NPYMATH_BITSOF_CHAR == 8
#ifndef NPYMATH_INT8
#define NPYMATH_INT8
        typedef unsigned char npymath_uint8;
#endif
#elif NPYMATH_BITSOF_CHAR == 16
#ifndef NPYMATH_INT16
#define NPYMATH_INT16
        typedef signed char npymath_int16;
        typedef unsigned char npymath_uint16;
#endif
#elif NPYMATH_BITSOF_CHAR == 32
#ifndef NPYMATH_INT32
#define NPYMATH_INT32
        typedef signed char npymath_int32;
        typedef unsigned char npymath_uint32;
#endif
#elif NPYMATH_BITSOF_CHAR == 64
#ifndef NPYMATH_INT64
#define NPYMATH_INT64
        typedef signed char npymath_int64;
        typedef unsigned char npymath_uint64;
#endif
#endif

#endif /* NPYMATH_USE_NUMPY_TYPES */

/* half/float16 isn't a floating-point type in C */
typedef npymath_uint16 npymath_half;

#endif  /* LIBNPYMATH_COMMON_H_ */
