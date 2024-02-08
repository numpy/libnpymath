#ifndef LIBNPYMATH_FPMATH_H_
#define LIBNPYMATH_FPMATH_H_

#include "libnpymath/block.h"

#include "libnpymath/cpu.h"
#include "libnpymath/common.h"

#if !(defined(NPYMATH_HAVE_LDOUBLE_IEEE_QUAD_BE) || \
      defined(NPYMATH_HAVE_LDOUBLE_IEEE_QUAD_LE) || \
      defined(NPYMATH_HAVE_LDOUBLE_IEEE_DOUBLE_LE) || \
      defined(NPYMATH_HAVE_LDOUBLE_IEEE_DOUBLE_BE) || \
      defined(NPYMATH_HAVE_LDOUBLE_INTEL_EXTENDED_16_BYTES_LE) || \
      defined(NPYMATH_HAVE_LDOUBLE_INTEL_EXTENDED_12_BYTES_LE) || \
      defined(NPYMATH_HAVE_LDOUBLE_MOTOROLA_EXTENDED_12_BYTES_BE) || \
      defined(NPYMATH_HAVE_LDOUBLE_IBM_DOUBLE_DOUBLE_BE) || \
      defined(NPYMATH_HAVE_LDOUBLE_IBM_DOUBLE_DOUBLE_LE))
    #error No long double representation defined
#endif

/* for back-compat, also keep old name for double-double */
#ifdef NPYMATH_HAVE_LDOUBLE_IBM_DOUBLE_DOUBLE_LE
    #define NPYMATH_HAVE_LDOUBLE_DOUBLE_DOUBLE_LE
#endif
#ifdef NPYMATH_HAVE_LDOUBLE_IBM_DOUBLE_DOUBLE_BE
    #define NPYMATH_HAVE_LDOUBLE_DOUBLE_DOUBLE_BE
#endif

#endif  /* LIBNPYMATH_FPMATH_H_ */
