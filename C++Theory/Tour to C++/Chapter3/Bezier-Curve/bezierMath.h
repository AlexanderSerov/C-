#ifndef _BEZIERMATH_H_
#define _BEZIERMATH_H_

#ifdef BEZIERMATH_EXPORTS
#define BEZIERMATH_API __declspec(dllexport)
#else
#define BEZIERMATH_API __declspec(dllimport)
#endif

BEZIERMATH_API float bernstein(int i, int n, float t);
BEZIERMATH_API float *deCasteljau(float **points, int degree, float t);

#endif
