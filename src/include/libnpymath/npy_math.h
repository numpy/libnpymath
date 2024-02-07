#ifndef LIBNPYMATH_NPY_MATH_H_
#define LIBNPYMATH_NPY_MATH_H_

#include "libnpymath/common.h"

#include <math.h>

#if defined(NPYMATH_INLINE_MATH)
#define NPYMATH_INPLACE static inline
#else
#define NPYMATH_INPLACE
#endif


#ifdef __cplusplus
extern "C" {
#endif

#define PyArray_MAX(a,b) (((a)>(b))?(a):(b))
#define PyArray_MIN(a,b) (((a)<(b))?(a):(b))

/*
 * NAN and INFINITY like macros (same behavior as glibc for NAN, same as C99
 * for INFINITY)
 *
 * XXX: I should test whether INFINITY and NAN are available on the platform
 */
static inline float __npymath_inff(void)
{
    const union { npymath_uint32 __i; float __f;} __bint = {0x7f800000UL};
    return __bint.__f;
}

static inline float __npymath_nanf(void)
{
    const union { npymath_uint32 __i; float __f;} __bint = {0x7fc00000UL};
    return __bint.__f;
}

static inline float __npymath_pzerof(void)
{
    const union { npymath_uint32 __i; float __f;} __bint = {0x00000000UL};
    return __bint.__f;
}

static inline float __npymath_nzerof(void)
{
    const union { npymath_uint32 __i; float __f;} __bint = {0x80000000UL};
    return __bint.__f;
}

#define NPYMATH_INFINITYF __npymath_inff()
#define NPYMATH_NANF __npymath_nanf()
#define NPYMATH_PZEROF __npymath_pzerof()
#define NPYMATH_NZEROF __npymath_nzerof()

#define NPYMATH_INFINITY ((npymath_double)NPYMATH_INFINITYF)
#define NPYMATH_NAN ((npymath_double)NPYMATH_NANF)
#define NPYMATH_PZERO ((npymath_double)NPYMATH_PZEROF)
#define NPYMATH_NZERO ((npymath_double)NPYMATH_NZEROF)

#define NPYMATH_INFINITYL ((npymath_longdouble)NPYMATH_INFINITYF)
#define NPYMATH_NANL ((npymath_longdouble)NPYMATH_NANF)
#define NPYMATH_PZEROL ((npymath_longdouble)NPYMATH_PZEROF)
#define NPYMATH_NZEROL ((npymath_longdouble)NPYMATH_NZEROF)

/*
 * Useful constants
 */
#define NPYMATH_E         2.718281828459045235360287471352662498  /* e */
#define NPYMATH_LOG2E     1.442695040888963407359924681001892137  /* log_2 e */
#define NPYMATH_LOG10E    0.434294481903251827651128918916605082  /* log_10 e */
#define NPYMATH_LOGE2     0.693147180559945309417232121458176568  /* log_e 2 */
#define NPYMATH_LOGE10    2.302585092994045684017991454684364208  /* log_e 10 */
#define NPYMATH_PI        3.141592653589793238462643383279502884  /* pi */
#define NPYMATH_PI_2      1.570796326794896619231321691639751442  /* pi/2 */
#define NPYMATH_PI_4      0.785398163397448309615660845819875721  /* pi/4 */
#define NPYMATH_1_PI      0.318309886183790671537767526745028724  /* 1/pi */
#define NPYMATH_2_PI      0.636619772367581343075535053490057448  /* 2/pi */
#define NPYMATH_EULER     0.577215664901532860606512090082402431  /* Euler constant */
#define NPYMATH_SQRT2     1.414213562373095048801688724209698079  /* sqrt(2) */
#define NPYMATH_SQRT1_2   0.707106781186547524400844362104849039  /* 1/sqrt(2) */

#define NPYMATH_Ef        2.718281828459045235360287471352662498F /* e */
#define NPYMATH_LOG2Ef    1.442695040888963407359924681001892137F /* log_2 e */
#define NPYMATH_LOG10Ef   0.434294481903251827651128918916605082F /* log_10 e */
#define NPYMATH_LOGE2f    0.693147180559945309417232121458176568F /* log_e 2 */
#define NPYMATH_LOGE10f   2.302585092994045684017991454684364208F /* log_e 10 */
#define NPYMATH_PIf       3.141592653589793238462643383279502884F /* pi */
#define NPYMATH_PI_2f     1.570796326794896619231321691639751442F /* pi/2 */
#define NPYMATH_PI_4f     0.785398163397448309615660845819875721F /* pi/4 */
#define NPYMATH_1_PIf     0.318309886183790671537767526745028724F /* 1/pi */
#define NPYMATH_2_PIf     0.636619772367581343075535053490057448F /* 2/pi */
#define NPYMATH_EULERf    0.577215664901532860606512090082402431F /* Euler constant */
#define NPYMATH_SQRT2f    1.414213562373095048801688724209698079F /* sqrt(2) */
#define NPYMATH_SQRT1_2f  0.707106781186547524400844362104849039F /* 1/sqrt(2) */

#define NPYMATH_El        2.718281828459045235360287471352662498L /* e */
#define NPYMATH_LOG2El    1.442695040888963407359924681001892137L /* log_2 e */
#define NPYMATH_LOG10El   0.434294481903251827651128918916605082L /* log_10 e */
#define NPYMATH_LOGE2l    0.693147180559945309417232121458176568L /* log_e 2 */
#define NPYMATH_LOGE10l   2.302585092994045684017991454684364208L /* log_e 10 */
#define NPYMATH_PIl       3.141592653589793238462643383279502884L /* pi */
#define NPYMATH_PI_2l     1.570796326794896619231321691639751442L /* pi/2 */
#define NPYMATH_PI_4l     0.785398163397448309615660845819875721L /* pi/4 */
#define NPYMATH_1_PIl     0.318309886183790671537767526745028724L /* 1/pi */
#define NPYMATH_2_PIl     0.636619772367581343075535053490057448L /* 2/pi */
#define NPYMATH_EULERl    0.577215664901532860606512090082402431L /* Euler constant */
#define NPYMATH_SQRT2l    1.414213562373095048801688724209698079L /* sqrt(2) */
#define NPYMATH_SQRT1_2l  0.707106781186547524400844362104849039L /* 1/sqrt(2) */

/*
 * Integer functions.
 */
NPYMATH_INPLACE npymath_uint npymath_gcdu(npymath_uint a, npymath_uint b);
NPYMATH_INPLACE npymath_uint npymath_lcmu(npymath_uint a, npymath_uint b);
NPYMATH_INPLACE npymath_ulong npymath_gcdul(npymath_ulong a, npymath_ulong b);
NPYMATH_INPLACE npymath_ulong npymath_lcmul(npymath_ulong a, npymath_ulong b);
NPYMATH_INPLACE npymath_ulonglong npymath_gcdull(npymath_ulonglong a, npymath_ulonglong b);
NPYMATH_INPLACE npymath_ulonglong npymath_lcmull(npymath_ulonglong a, npymath_ulonglong b);

NPYMATH_INPLACE npymath_int npymath_gcd(npymath_int a, npymath_int b);
NPYMATH_INPLACE npymath_int npymath_lcm(npymath_int a, npymath_int b);
NPYMATH_INPLACE npymath_long npymath_gcdl(npymath_long a, npymath_long b);
NPYMATH_INPLACE npymath_long npymath_lcml(npymath_long a, npymath_long b);
NPYMATH_INPLACE npymath_longlong npymath_gcdll(npymath_longlong a, npymath_longlong b);
NPYMATH_INPLACE npymath_longlong npymath_lcmll(npymath_longlong a, npymath_longlong b);

NPYMATH_INPLACE npymath_ubyte npymath_rshiftuhh(npymath_ubyte a, npymath_ubyte b);
NPYMATH_INPLACE npymath_ubyte npymath_lshiftuhh(npymath_ubyte a, npymath_ubyte b);
NPYMATH_INPLACE npymath_ushort npymath_rshiftuh(npymath_ushort a, npymath_ushort b);
NPYMATH_INPLACE npymath_ushort npymath_lshiftuh(npymath_ushort a, npymath_ushort b);
NPYMATH_INPLACE npymath_uint npymath_rshiftu(npymath_uint a, npymath_uint b);
NPYMATH_INPLACE npymath_uint npymath_lshiftu(npymath_uint a, npymath_uint b);
NPYMATH_INPLACE npymath_ulong npymath_rshiftul(npymath_ulong a, npymath_ulong b);
NPYMATH_INPLACE npymath_ulong npymath_lshiftul(npymath_ulong a, npymath_ulong b);
NPYMATH_INPLACE npymath_ulonglong npymath_rshiftull(npymath_ulonglong a, npymath_ulonglong b);
NPYMATH_INPLACE npymath_ulonglong npymath_lshiftull(npymath_ulonglong a, npymath_ulonglong b);

NPYMATH_INPLACE npymath_byte npymath_rshifthh(npymath_byte a, npymath_byte b);
NPYMATH_INPLACE npymath_byte npymath_lshifthh(npymath_byte a, npymath_byte b);
NPYMATH_INPLACE npymath_short npymath_rshifth(npymath_short a, npymath_short b);
NPYMATH_INPLACE npymath_short npymath_lshifth(npymath_short a, npymath_short b);
NPYMATH_INPLACE npymath_int npymath_rshift(npymath_int a, npymath_int b);
NPYMATH_INPLACE npymath_int npymath_lshift(npymath_int a, npymath_int b);
NPYMATH_INPLACE npymath_long npymath_rshiftl(npymath_long a, npymath_long b);
NPYMATH_INPLACE npymath_long npymath_lshiftl(npymath_long a, npymath_long b);
NPYMATH_INPLACE npymath_longlong npymath_rshiftll(npymath_longlong a, npymath_longlong b);
NPYMATH_INPLACE npymath_longlong npymath_lshiftll(npymath_longlong a, npymath_longlong b);

NPYMATH_INPLACE uint8_t npymath_popcountuhh(npymath_ubyte a);
NPYMATH_INPLACE uint8_t npymath_popcountuh(npymath_ushort a);
NPYMATH_INPLACE uint8_t npymath_popcountu(npymath_uint a);
NPYMATH_INPLACE uint8_t npymath_popcountul(npymath_ulong a);
NPYMATH_INPLACE uint8_t npymath_popcountull(npymath_ulonglong a);
NPYMATH_INPLACE uint8_t npymath_popcounthh(npymath_byte a);
NPYMATH_INPLACE uint8_t npymath_popcounth(npymath_short a);
NPYMATH_INPLACE uint8_t npymath_popcount(npymath_int a);
NPYMATH_INPLACE uint8_t npymath_popcountl(npymath_long a);
NPYMATH_INPLACE uint8_t npymath_popcountll(npymath_longlong a);

/*
 * C99 double math funcs that need fixups or are blocklist-able
 */
NPYMATH_INPLACE double npymath_sin(double x);
NPYMATH_INPLACE double npymath_cos(double x);
NPYMATH_INPLACE double npymath_tan(double x);
NPYMATH_INPLACE double npymath_hypot(double x, double y);
NPYMATH_INPLACE double npymath_log2(double x);
NPYMATH_INPLACE double npymath_atan2(double x, double y);

/* Mandatory C99 double math funcs, no blocklisting or fixups */
/* defined for legacy reasons, should be deprecated at some point */
#define npymath_sinh sinh
#define npymath_cosh cosh
#define npymath_tanh tanh
#define npymath_asin asin
#define npymath_acos acos
#define npymath_atan atan
#define npymath_log log
#define npymath_log10 log10
#define npymath_cbrt cbrt
#define npymath_fabs fabs
#define npymath_ceil ceil
#define npymath_fmod fmod
#define npymath_floor floor
#define npymath_expm1 expm1
#define npymath_log1p log1p
#define npymath_acosh acosh
#define npymath_asinh asinh
#define npymath_atanh atanh
#define npymath_rint rint
#define npymath_trunc trunc
#define npymath_exp2 exp2
#define npymath_frexp frexp
#define npymath_ldexp ldexp
#define npymath_copysign copysign
#define npymath_exp exp
#define npymath_sqrt sqrt
#define npymath_pow pow
#define npymath_modf modf
#define npymath_nextafter nextafter

double npymath_spacing(double x);

/*
 * IEEE 754 fpu handling
 */

/* use builtins to avoid function calls in tight loops
 * only available if npymath_config.h is available (= numpys own build) */
#ifdef NPYMATH_HAVE___BUILTIN_ISNAN
    #define npymath_isnan(x) __builtin_isnan(x)
#else
    #define npymath_isnan(x) isnan(x)
#endif


/* only available if npymath_config.h is available (= numpys own build) */
#ifdef NPYMATH_HAVE___BUILTIN_ISFINITE
    #define npymath_isfinite(x) __builtin_isfinite(x)
#else
    #define npymath_isfinite(x) isfinite((x))
#endif

/* only available if npymath_config.h is available (= numpys own build) */
#ifdef NPYMATH_HAVE___BUILTIN_ISINF
    #define npymath_isinf(x) __builtin_isinf(x)
#else
    #define npymath_isinf(x) isinf((x))
#endif

#define npymath_signbit(x) signbit((x))

/*
 * float C99 math funcs that need fixups or are blocklist-able
 */
NPYMATH_INPLACE float npymath_sinf(float x);
NPYMATH_INPLACE float npymath_cosf(float x);
NPYMATH_INPLACE float npymath_tanf(float x);
NPYMATH_INPLACE float npymath_expf(float x);
NPYMATH_INPLACE float npymath_sqrtf(float x);
NPYMATH_INPLACE float npymath_hypotf(float x, float y);
NPYMATH_INPLACE float npymath_log2f(float x);
NPYMATH_INPLACE float npymath_atan2f(float x, float y);
NPYMATH_INPLACE float npymath_powf(float x, float y);
NPYMATH_INPLACE float npymath_modff(float x, float* y);

/* Mandatory C99 float math funcs, no blocklisting or fixups */
/* defined for legacy reasons, should be deprecated at some point */

#define npymath_sinhf sinhf
#define npymath_coshf coshf
#define npymath_tanhf tanhf
#define npymath_asinf asinf
#define npymath_acosf acosf
#define npymath_atanf atanf
#define npymath_logf logf
#define npymath_log10f log10f
#define npymath_cbrtf cbrtf
#define npymath_fabsf fabsf
#define npymath_ceilf ceilf
#define npymath_fmodf fmodf
#define npymath_floorf floorf
#define npymath_expm1f expm1f
#define npymath_log1pf log1pf
#define npymath_asinhf asinhf
#define npymath_acoshf acoshf
#define npymath_atanhf atanhf
#define npymath_rintf rintf
#define npymath_truncf truncf
#define npymath_exp2f exp2f
#define npymath_frexpf frexpf
#define npymath_ldexpf ldexpf
#define npymath_copysignf copysignf
#define npymath_nextafterf nextafterf

float npymath_spacingf(float x);

/*
 * long double C99 double math funcs that need fixups or are blocklist-able
 */
NPYMATH_INPLACE npymath_longdouble npymath_sinl(npymath_longdouble x);
NPYMATH_INPLACE npymath_longdouble npymath_cosl(npymath_longdouble x);
NPYMATH_INPLACE npymath_longdouble npymath_tanl(npymath_longdouble x);
NPYMATH_INPLACE npymath_longdouble npymath_expl(npymath_longdouble x);
NPYMATH_INPLACE npymath_longdouble npymath_sqrtl(npymath_longdouble x);
NPYMATH_INPLACE npymath_longdouble npymath_hypotl(npymath_longdouble x, npymath_longdouble y);
NPYMATH_INPLACE npymath_longdouble npymath_log2l(npymath_longdouble x);
NPYMATH_INPLACE npymath_longdouble npymath_atan2l(npymath_longdouble x, npymath_longdouble y);
NPYMATH_INPLACE npymath_longdouble npymath_powl(npymath_longdouble x, npymath_longdouble y);
NPYMATH_INPLACE npymath_longdouble npymath_modfl(npymath_longdouble x, npymath_longdouble* y);

/* Mandatory C99 double math funcs, no blocklisting or fixups */
/* defined for legacy reasons, should be deprecated at some point */
#define npymath_sinhl sinhl
#define npymath_coshl coshl
#define npymath_tanhl tanhl
#define npymath_fabsl fabsl
#define npymath_floorl floorl
#define npymath_ceill ceill
#define npymath_rintl rintl
#define npymath_truncl truncl
#define npymath_cbrtl cbrtl
#define npymath_log10l log10l
#define npymath_logl logl
#define npymath_expm1l expm1l
#define npymath_asinl asinl
#define npymath_acosl acosl
#define npymath_atanl atanl
#define npymath_asinhl asinhl
#define npymath_acoshl acoshl
#define npymath_atanhl atanhl
#define npymath_log1pl log1pl
#define npymath_exp2l exp2l
#define npymath_fmodl fmodl
#define npymath_frexpl frexpl
#define npymath_ldexpl ldexpl
#define npymath_copysignl copysignl
#define npymath_nextafterl nextafterl

npymath_longdouble npymath_spacingl(npymath_longdouble x);

/*
 * Non standard functions
 */
NPYMATH_INPLACE double npymath_deg2rad(double x);
NPYMATH_INPLACE double npymath_rad2deg(double x);
NPYMATH_INPLACE double npymath_logaddexp(double x, double y);
NPYMATH_INPLACE double npymath_logaddexp2(double x, double y);
NPYMATH_INPLACE double npymath_divmod(double x, double y, double *modulus);
NPYMATH_INPLACE double npymath_heaviside(double x, double h0);

NPYMATH_INPLACE float npymath_deg2radf(float x);
NPYMATH_INPLACE float npymath_rad2degf(float x);
NPYMATH_INPLACE float npymath_logaddexpf(float x, float y);
NPYMATH_INPLACE float npymath_logaddexp2f(float x, float y);
NPYMATH_INPLACE float npymath_divmodf(float x, float y, float *modulus);
NPYMATH_INPLACE float npymath_heavisidef(float x, float h0);

NPYMATH_INPLACE npymath_longdouble npymath_deg2radl(npymath_longdouble x);
NPYMATH_INPLACE npymath_longdouble npymath_rad2degl(npymath_longdouble x);
NPYMATH_INPLACE npymath_longdouble npymath_logaddexpl(npymath_longdouble x, npymath_longdouble y);
NPYMATH_INPLACE npymath_longdouble npymath_logaddexp2l(npymath_longdouble x, npymath_longdouble y);
NPYMATH_INPLACE npymath_longdouble npymath_divmodl(npymath_longdouble x, npymath_longdouble y,
                           npymath_longdouble *modulus);
NPYMATH_INPLACE npymath_longdouble npymath_heavisidel(npymath_longdouble x, npymath_longdouble h0);

#define npymath_degrees npymath_rad2deg
#define npymath_degreesf npymath_rad2degf
#define npymath_degreesl npymath_rad2degl

#define npymath_radians npymath_deg2rad
#define npymath_radiansf npymath_deg2radf
#define npymath_radiansl npymath_deg2radl

/*
 * Complex declarations
 */

npymath_double npymath_creal(const npymath_cdouble *z);
void npymath_csetreal(npymath_cdouble *z, npymath_double r);
npymath_double npymath_cimag(const npymath_cdouble *z);
void npymath_csetimag(npymath_cdouble *z, npymath_double i);
npymath_float npymath_crealf(const npymath_cfloat *z);
void npymath_csetrealf(npymath_cfloat *z, npymath_float r);
npymath_float npymath_cimagf(const npymath_cfloat *z);
void npymath_csetimagf(npymath_cfloat *z, npymath_float i);
npymath_longdouble npymath_creall(const npymath_clongdouble *z);
void npymath_csetreall(npymath_clongdouble *z, npymath_longdouble r);
npymath_longdouble npymath_cimagl(const npymath_clongdouble *z);
void npymath_csetimagl(npymath_clongdouble *z, npymath_longdouble i);

npymath_cdouble npymath_cpack(npymath_double x, npymath_double y);
npymath_cfloat npymath_cpackf(npymath_float x, npymath_float y);
npymath_clongdouble npymath_cpackl(npymath_longdouble x, npymath_longdouble y);

/*
 * Double precision complex functions
 */
double npymath_cabs(npymath_cdouble z);
double npymath_carg(npymath_cdouble z);

npymath_cdouble npymath_cexp(npymath_cdouble z);
npymath_cdouble npymath_clog(npymath_cdouble z);
npymath_cdouble npymath_cpow(npymath_cdouble x, npymath_cdouble y);

npymath_cdouble npymath_csqrt(npymath_cdouble z);

npymath_cdouble npymath_ccos(npymath_cdouble z);
npymath_cdouble npymath_csin(npymath_cdouble z);
npymath_cdouble npymath_ctan(npymath_cdouble z);

npymath_cdouble npymath_ccosh(npymath_cdouble z);
npymath_cdouble npymath_csinh(npymath_cdouble z);
npymath_cdouble npymath_ctanh(npymath_cdouble z);

npymath_cdouble npymath_cacos(npymath_cdouble z);
npymath_cdouble npymath_casin(npymath_cdouble z);
npymath_cdouble npymath_catan(npymath_cdouble z);

npymath_cdouble npymath_cacosh(npymath_cdouble z);
npymath_cdouble npymath_casinh(npymath_cdouble z);
npymath_cdouble npymath_catanh(npymath_cdouble z);

/*
 * Single precision complex functions
 */
float npymath_cabsf(npymath_cfloat z);
float npymath_cargf(npymath_cfloat z);

npymath_cfloat npymath_cexpf(npymath_cfloat z);
npymath_cfloat npymath_clogf(npymath_cfloat z);
npymath_cfloat npymath_cpowf(npymath_cfloat x, npymath_cfloat y);

npymath_cfloat npymath_csqrtf(npymath_cfloat z);

npymath_cfloat npymath_ccosf(npymath_cfloat z);
npymath_cfloat npymath_csinf(npymath_cfloat z);
npymath_cfloat npymath_ctanf(npymath_cfloat z);

npymath_cfloat npymath_ccoshf(npymath_cfloat z);
npymath_cfloat npymath_csinhf(npymath_cfloat z);
npymath_cfloat npymath_ctanhf(npymath_cfloat z);

npymath_cfloat npymath_cacosf(npymath_cfloat z);
npymath_cfloat npymath_casinf(npymath_cfloat z);
npymath_cfloat npymath_catanf(npymath_cfloat z);

npymath_cfloat npymath_cacoshf(npymath_cfloat z);
npymath_cfloat npymath_casinhf(npymath_cfloat z);
npymath_cfloat npymath_catanhf(npymath_cfloat z);


/*
 * Extended precision complex functions
 */
npymath_longdouble npymath_cabsl(npymath_clongdouble z);
npymath_longdouble npymath_cargl(npymath_clongdouble z);

npymath_clongdouble npymath_cexpl(npymath_clongdouble z);
npymath_clongdouble npymath_clogl(npymath_clongdouble z);
npymath_clongdouble npymath_cpowl(npymath_clongdouble x, npymath_clongdouble y);

npymath_clongdouble npymath_csqrtl(npymath_clongdouble z);

npymath_clongdouble npymath_ccosl(npymath_clongdouble z);
npymath_clongdouble npymath_csinl(npymath_clongdouble z);
npymath_clongdouble npymath_ctanl(npymath_clongdouble z);

npymath_clongdouble npymath_ccoshl(npymath_clongdouble z);
npymath_clongdouble npymath_csinhl(npymath_clongdouble z);
npymath_clongdouble npymath_ctanhl(npymath_clongdouble z);

npymath_clongdouble npymath_cacosl(npymath_clongdouble z);
npymath_clongdouble npymath_casinl(npymath_clongdouble z);
npymath_clongdouble npymath_catanl(npymath_clongdouble z);

npymath_clongdouble npymath_cacoshl(npymath_clongdouble z);
npymath_clongdouble npymath_casinhl(npymath_clongdouble z);
npymath_clongdouble npymath_catanhl(npymath_clongdouble z);


/*
 * Functions that set the floating point error
 * status word.
 */

/*
 * platform-dependent code translates floating point
 * status to an integer sum of these values
 */
#define NPYMATH_FPE_DIVIDEBYZERO  1
#define NPYMATH_FPE_OVERFLOW      2
#define NPYMATH_FPE_UNDERFLOW     4
#define NPYMATH_FPE_INVALID       8

int npymath_clear_floatstatus_barrier(char*);
int npymath_get_floatstatus_barrier(char*);
/*
 * use caution with these - clang and gcc8.1 are known to reorder calls
 * to this form of the function which can defeat the check. The _barrier
 * form of the call is preferable, where the argument is
 * (char*)&local_variable
 */
int npymath_clear_floatstatus(void);
int npymath_get_floatstatus(void);

void npymath_set_floatstatus_divbyzero(void);
void npymath_set_floatstatus_overflow(void);
void npymath_set_floatstatus_underflow(void);
void npymath_set_floatstatus_invalid(void);

#ifdef __cplusplus
}
#endif

#ifdef NPYMATH_INLINE_MATH
#include "libnpymath/internal.h"
#endif

#endif  /* LIBNPYMATH_NPY_MATH_H_ */
