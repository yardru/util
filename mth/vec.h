#ifndef _VEC_H_
#define _VEC_H_

#include "def.h"
// "vec_imp.h" file included in the end of file

namespace mth
{
    /* vector class
     *     n - component number
     *     type - component type
     */
    template <uint n, typename type = BASE_REAL_TYPE>
        class vec_t
        {
        protected:
            type _components[n]; // components
        public:
            type &x, &y, &z, &w; // references as coordinates
            type &r, &g, &b, &a; // references as colors
            type &s, &t, &p, &q; // references as texture coordinates
        protected:
            // make copy of the vector
            vec_t & clone(const vec_t &);
        public:
            // constructors
            vec_t();
            vec_t(const vec_t &);
            vec_t(const type *);
            vec_t(const type &);
            vec_t(type, type, ...);
            // math operators
            vec_t & operator+=(const vec_t &);
            vec_t & operator-=(const vec_t &);
            vec_t & operator*=(const type &);
            vec_t & operator*=(const vec_t &); // component-wise product
            vec_t & operator/=(const type &);
            vec_t & operator/=(const vec_t &); // component-wise division
            // other operators
            vec_t & operator=(const vec_t &);
            type & operator[](uint);
            type operator[](uint) const;
            // setters
            vec_t & set(const vec_t &);
            vec_t & set(const type *);
            vec_t & set(const type &);
            vec_t & set(type, type, ...);
            // get vector lenght
            type lenght() const;
            // normalize vector
            vec_t & normalize();       // self
            vec_t normalizing() const; // to another
        };

    // math operators
    template <uint n, typename type>
        vec_t<n, type> operator-(const vec_t<n, type> &);
    template <uint n, typename type>
        vec_t<n, type> operator+(const vec_t<n, type> &, const vec_t<n, type> &);
    template <uint n, typename type>
        vec_t<n, type> operator-(const vec_t<n, type> &, const vec_t<n, type> &);
    template <uint n, typename type>
        vec_t<n, type> operator*(const vec_t<n, type> &, const type &);
    template <uint n, typename type>
        vec_t<n, type> operator*(const type &, const vec_t<n, type> &);
    template <uint n, typename type>
        vec_t<n, type> operator*(const vec_t<n, type> &, const vec_t<n, type> &); // component-wise product
    template <uint n, typename type>
        type           operator&(const vec_t<n, type> &, const vec_t<n, type> &); // scalar product
    template <uint n, typename type>
        vec_t<n, type> operator/(const vec_t<n, type> &, const type &);
    template <uint n, typename type>
        vec_t<n, type> operator/(const type &, const vec_t<n, type> &);
    template <uint n, typename type>
        vec_t<n, type> operator/(const vec_t<n, type> &, const vec_t<n, type> &); // component-wise division
    // order operators
    template <uint n, typename type>
        bool operator==(const vec_t<n, type> &, const vec_t<n, type> &);
    template <uint n, typename type>
        bool operator!=(const vec_t<n, type> &, const vec_t<n, type> &);
    // cross product operator for 3d vectors
    template <typename type>
        vec_t<3, type> & operator%=(const vec_t<3, type> &, const vec_t<3, type> &);
    template <typename type>
        vec_t<3, type> operator%(const vec_t<3, type> &, const vec_t<3, type> &);
}

// vector absolut value
template <uint n, typename type>
    type abs(const mth::vec_t<n, type> &);
// iostream input/output definition
template <uint n, typename type>
    std::istream & operator>>(std::istream &is, mth::vec_t<n, type> &);
template <uint n, typename type>
    std::ostream & operator<<(std::ostream &os, const mth::vec_t<n, type> &);

#include "vec_imp.h"

#endif // _VEC_H_
