#ifndef _TEMPLATE_H_
#define _TEMPLATE_H_

#include "def.h"
// "fixed_imp.h" file included in the end of file

namespace mth
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
            fixed_t(const fixed_t &);
            template <uint m>
                fixed_t(const fixed_t<m, type> &);
            fixed_t(int);
            fixed_t(double);
            // math operators
            fixed_t & operator+=(const fixed_t &);
            fixed_t & operator-=(const fixed_t &);
            fixed_t & operator*=(const fixed_t &);
            fixed_t & operator/=(const fixed_t &);
            // type conversation
            operator int() const;
            operator double() const;
        };
}

// iostream input/output definition
template <uint n, typename type>
    std::istream & operator>>(std::istream &is, mth::fixed_t<n, type> &);
template <uint n, typename type>
    std::ostream & operator<<(std::ostream &os, const mth::fixed_t<n, type> &);

//#include "fixed_imp.h"

#endif // _TEMPLATE_H_
