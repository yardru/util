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
            vec_t & clone(const vec_t &vec);
        public:
            // constructors
            vec_t();
            vec_t(const vec_t &vec);
            vec_t(const type &value);
            vec_t(const type *values);
            vec_t(type value1, type value2, ...);
            // math operators
            vec_t & operator+=(const vec_t &vec);
            vec_t & operator-=(const vec_t &vec);
            vec_t & operator*=(const type &value);
            vec_t & operator*=(const vec_t &vec); // component-wise product
            vec_t & operator/=(const type &value);
            vec_t & operator/=(const vec_t &vec); // component-wise division
            // other operators
            vec_t & operator=(const vec_t &vec);
            type & operator[](uint i);
            type operator[](uint i) const;
            // setters
            vec_t & set(const vec_t & vec);
            vec_t & set(const type *value);
            vec_t & set(const type &value);
            vec_t & set(type value1, type value2, ...);
            // get vector lenght
            type lenght() const;
            // normalize vector
            vec_t & normalize();       // self
            vec_t normalizing() const; // to another
        };

    // math operators
    template <uint n, typename type>
        vec_t<n, type> operator-(const vec_t<n, type> &vec);
    template <uint n, typename type>
        vec_t<n, type> operator+(const vec_t<n, type> &vec1, const vec_t<n, type> &vec2);
    template <uint n, typename type>
        vec_t<n, type> operator-(const vec_t<n, type> &vec1, const vec_t<n, type> &vec2);
    template <uint n, typename type>
        vec_t<n, type> operator*(const vec_t<n, type> &vec, const type &value);
    template <uint n, typename type>
        vec_t<n, type> operator*(const type &value, const vec_t<n, type> &vec);
    template <uint n, typename type>
        vec_t<n, type> operator*(const vec_t<n, type> &vec1, const vec_t<n, type> &vec2); // component-wise product
    template <uint n, typename type>
        type           operator&(const vec_t<n, type> &vec1, const vec_t<n, type> &vec2); // scalar product
    template <uint n, typename type>
        vec_t<n, type> operator/(const vec_t<n, type> &vec, const type &value);
    template <uint n, typename type>
        vec_t<n, type> operator/(const type &value, const vec_t<n, type> &vec);
    template <uint n, typename type>
        vec_t<n, type> operator/(const vec_t<n, type> &vec1, const vec_t<n, type> &vec2); // component-wise division
    // order operators
    template <uint n, typename type>
        bool operator==(const vec_t<n, type> &vec1, const vec_t<n, type> &vec2);
    template <uint n, typename type>
        bool operator!=(const vec_t<n, type> &vec1, const vec_t<n, type> &vec2);
    // cross product operator for 3d vectors
    template <typename type>
        vec_t<3, type> & operator%=(const vec_t<3, type> &vec1, const vec_t<3, type> &vec2);
    template <typename type>
        vec_t<3, type> operator%(const vec_t<3, type> &vec1, const vec_t<3, type> &vec2);
}

// vector absolut value
template <uint n, typename type>
    type abs(const mth::vec_t<n, type> &vec);
// iostream input/output definition
template <uint n, typename type>
    std::istream & operator>>(std::istream &is, mth::vec_t<n, type> &vec);
template <uint n, typename type>
    std::ostream & operator<<(std::ostream &os, const mth::vec_t<n, type> &vec);

#include "vec_imp.h"

#endif // _VEC_H_
