#ifndef _COMP_H_
#define _COMP_H_

#include "def.h"
// "comp_imp.h" file included in the end of file

namespace mth
{
    /* complex number class
     *     real_type - component type
     */
    template <typename real_type = BASE_REAL_TYPE>
        class comp_t
        {
        protected:
            real_type _real, _imag; // complex components
        public:
            real_type &re, &im;          // references as geometry model
            real_type &x, &y;            // references as analytic model
            // constructors
            comp_t();
            comp_t(const comp_t &);
            comp_t(const real_type &, const real_type & = 0);
            // math operators
            comp_t & operator+=(const comp_t &);
            comp_t & operator-=(const comp_t &);
            comp_t & operator*=(const comp_t &);
            comp_t & operator/=(const comp_t &);
            // other operators
            comp_t & operator=(const comp_t &);
            // math functions
            real_type abs(); // absolut value
            real_type arg(); // argument
        };
    // math operators
    template <typename real_type>
        comp_t<real_type> operator-(const comp_t<real_type> &);
    template <typename real_type>
        comp_t<real_type> operator!(const comp_t<real_type> &); // complex conjugate
    template <typename real_type>
        comp_t<real_type> operator+(const comp_t<real_type> &, const comp_t<real_type> &);
    template <typename real_type>
        comp_t<real_type> operator-(const comp_t<real_type> &, const comp_t<real_type> &);
    template <typename real_type>
        comp_t<real_type> operator*(const comp_t<real_type> &, const comp_t<real_type> &);
    template <typename real_type>
        comp_t<real_type> operator/(const comp_t<real_type> &, const comp_t<real_type> &);
    // order operators
    template <typename real_type>
        bool operator==(const comp_t<real_type> &, const comp_t<real_type> &);
    template <typename real_type>
        bool operator!=(const comp_t<real_type> &, const comp_t<real_type> &);
}

// absolute comlex number value
template <typename real_type>
    real_type abs(const mth::comp_t<real_type> &);
// iostream input/output definition
template <typename real_type>
    std::istream & operator>>(std::istream &is, mth::comp_t<real_type> &);
template <typename real_type>
    std::ostream & operator<<(std::ostream &os, const mth::comp_t<real_type> &);

#include "comp_imp.h"

#endif // _COMP_H_
