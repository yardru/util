#ifndef _UTIL_H_
#define _UTIL_H_

#include <iostream>
#include <math.h>

#include "../def/def.h"

#ifndef BASE_INT_TYPE
    #define BASE_INT_TYPE int
#endif // BASE_INT_TYPE

#ifndef BASE_REAL_TYPE
    #define BASE_REAL_TYPE double
#endif // BASE_REAL_TYPE

namespace mth
{
    const double PI = 3.14159265358979323846;
    const double E  = 2.71828182845904523536;

    const double SQRT2  = 1.41421356237309504880;
    const double SQRT3  = 1.73205080756887729352;
    const double SQRT5  = 2.23606797749978969640;

    // factorial of number
    __inline uint factorial(uint n)
        {
            if (n <= 1)
                return 1;

            return factorial(n - 1) * n;
        }

    // binominal coefficient
    __inline uint binominal(uint n, uint k)
        {
            if (k > n)
                return 0;

            if (k == 0 || k == n)
                return 1;

            return binominal(n - 1, k - 1) + binominal(n - 1, k);
        }

    // sign of argument
    template<typename type>
        int sign(const type &a)
        {
            return (a > 0) - (a < 0);
        }

    // second degree of argument
    template<typename type>
        type sqr(const type &a)
        {
            return a * a;
        }

    // greatest common divisor of two argument
    template<typename type>
        type gcd(const type &a, const type &b)
        {
            return (a > 0) ? gcd(b % a, a) : b;
        }

    // least common multiple of two argument
    template<typename type>
        type lcm(const type &a, const type &b)
        {
            return a * b / gcd(a, b);
        }
}

// integer degree of argument
template<typename type>
    type pow(const type &a, int d)
    {
        if (d < 0)
            return type(1) / pow(a, -d);

        type r(1), b(a);

        while (d > 0)
        {
            if (d % 2)
                r *= b;
            b *= b;
            d /= 2;
        }

        return r;
    }

#endif // _UTIL_H_
