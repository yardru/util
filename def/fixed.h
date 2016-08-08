#ifndef _FIXED_H_
#define _FIXED_H_

#include <def/def.h>
// "fixed_imp.h" file included in the end of file

namespace def
{
    /* fixed real type class
     *     n - numbers after dot number
     *     type - component type (integer)
     */
    template <uint n, typename type = int>
        class fixed_t
        {
        protected:
            static const type _denominator;
            type _value;
        public:
            // constructors
            fixed_t();
            fixed_t(const fixed_t &fixed);
            template <uint m>
                fixed_t(const fixed_t<m, type> &fixed);
            fixed_t(int value);
            fixed_t(double value);
            // math operators
            fixed_t & operator+=(const fixed_t &fixed);
            fixed_t & operator-=(const fixed_t &fixed);
            fixed_t & operator*=(const fixed_t &fixed);
            fixed_t & operator/=(const fixed_t &fixed);
            // type conversation
            operator int() const;
            operator double() const;
            // order funcs
            bool equal(const fixed_t &fixed) const;
            bool less(const fixed_t &fixed) const;
        };
    // order operators
    template <uint n, typename type>
        bool operator==(const fixed_t<n, type> &fixed1, const fixed_t<n, type> &fixed2);
    template <uint n, typename type>
        bool operator!=(const fixed_t<n, type> &fixed1, const fixed_t<n, type> &fixed2);
    template <uint n, typename type>
        bool operator>(const fixed_t<n, type> &fixed1, const fixed_t<n, type> &fixed2);
    template <uint n, typename type>
        bool operator<(const fixed_t<n, type> &fixed1, const fixed_t<n, type> &fixed2);
    template <uint n, typename type>
        bool operator>=(const fixed_t<n, type> &fixed1, const fixed_t<n, type> &fixed2);
    template <uint n, typename type>
        bool operator<=(const fixed_t<n, type> &fixed1, const fixed_t<n, type> &fixed2);
    // math operators
    template <uint n, typename type>
        fixed_t<n, type> operator-(const fixed_t<n, type> &fixed);
    template <uint n, typename type>
        fixed_t<n, type> operator+(const fixed_t<n, type> &fixed1, const fixed_t<n, type> &fixed2);
    template <uint n, typename type>
        fixed_t<n, type> operator-(const fixed_t<n, type> &fixed1, const fixed_t<n, type> &fixed2);
    template <uint n, typename type>
        fixed_t<n, type> operator*(const fixed_t<n, type> &fixed1, const fixed_t<n, type> &fixed2);
    template <uint n, typename type>
        fixed_t<n, type> operator/(const fixed_t<n, type> &fixed1, const fixed_t<n, type> &fixed2);
}

// iostream input/output definition
template <uint n, typename type>
    std::istream & operator>>(std::istream &is, def::fixed_t<n, type> &);
template <uint n, typename type>
    std::ostream & operator<<(std::ostream &os, const def::fixed_t<n, type> &);

#include "fixed_imp.h"

#endif // _FIXED_H_
