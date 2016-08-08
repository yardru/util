#ifndef _MATR_H_
#define _MATR_H_

#include "def.h"
#include "vec.h"
// "matr_imp.h" file included in the end of file

namespace mth
{
    /* matrix class
     *     m - rows number (i changes)
     *     n - columns number (j changes)
     *     type - component type
     */
    template <uint m, uint n, typename type = BASE_REAL_TYPE>
        class matr_t
        {
        protected:
            type _components[m * n]; // components
            // make copy of the matrix
            matr_t & clone(const matr_t &matr);
        public:
            // constructors
            matr_t();
            matr_t(const matr_t &matr);
            matr_t(const type &value);
            matr_t(const type *values);
            matr_t(const type **values);
            matr_t(type value1, type value2, ...);
            // math operators
            matr_t & operator+=(const matr_t &matr);
            matr_t & operator-=(const matr_t &value);
            matr_t & operator*=(const type &value);
            matr_t & operator/=(const type &value);
            // other operators
            matr_t & operator=(const matr_t &matr);
            type & operator()(uint i, uint j);
            type operator()(uint i, uint j) const;
            type * operator[](uint i);
            const type * operator[](uint i) const;
            // setters
            matr_t & set(const matr_t &matr);
            matr_t & set(const type &value);
            matr_t & set(const type *values);
            matr_t & set(const type **values);
            matr_t & set(type value1, type value2, ...);
            // setters/getters for rows and columns
            matr_t & set_row(uint i, const type &value);
            matr_t & set_row(uint i, const type *values);
            type * get_row(uint i, type *to) const;
            type * get_row(uint i);
            matr_t & set_col(uint j, const type &value);
            matr_t & set_col(uint j, const type *values);
            type * get_col(uint j, type *to) const;
            // transpose matrix
            matr_t<n, m, type> transposing() const; // to other
            // elementary operations
            matr_t & row_mul(uint i, const type &value);  // multiply row by number
            matr_t & row_add_to(uint i_to, uint i_from,
                const type &scale = type(1));           // add scaled second row to first
            matr_t & row_swap(uint i1, uint i2);         // swap two rows
            matr_t & col_mul(uint j, const type &value);  // multiply column by number
            matr_t & col_add_to(uint j_to, uint j_from,
                const type &scale = type(1));           // add scaled second column to first
            matr_t & col_swap(uint j1, uint j2);         // swap two columns
            // math functions for square matrix
            matr_t & transpose();
            type trace() const;
            matr_t<n - 1, n - 1, type> minor(uint i, uint j) const;
            type cofactor(uint i, uint j) const;
            type det() const;
            matr_t & invert();
            matr_t inverting() const;
        };

    // transpose to other matrix functions
    template <uint m, uint n, typename type>
        matr_t<n, m, type> transposing(const matr_t<m, n, type> &matr);
    // functions for square matrix
    template <uint n, typename type>
        matr_t<n, n, type> & transpose(matr_t<n, n, type> &matr);
    template <uint n, typename type>
        matr_t<n - 1, n - 1, type> minor(const matr_t<n, n, type> &matr, uint i, uint j);
    template <uint n, typename type>
        type det(const matr_t<n, n, type> &matr);
    template <uint n, typename type>
        type cofactor(const matr_t<n, n, type> &matr, uint i, uint j);
    template <uint n, typename type>
        type trace(const matr_t<n, n, type> &matr);
    template <uint n, typename type>
        matr_t<n, n, type> inverting(const matr_t<n, n, type> &matr);
    template <uint n, typename type>
        matr_t<n, n, type> & invert(matr_t<n, n, type> &matr);
    template <uint n, typename type>
        matr_t<n, n, type> inv(const matr_t<n, n, type> &matr); // same as inverting
    // matrix simple math operators
    template <uint m, uint n, typename type>
        matr_t<m, n, type> operator-(const matr_t<m, n, type> &matr);
    template <uint m, uint n, typename type>
        matr_t<m, n, type> operator+(const matr_t<m, n, type> &matr1, const matr_t<m, n, type> &matr2);
    template <uint m, uint n, typename type>
        matr_t<m, n, type> operator-(const matr_t<m, n, type> &matr1, const matr_t<m, n, type> &matr2);
    template <uint m, uint n, typename type>
        matr_t<m, n, type> operator*(const matr_t<m, n, type> &matr, const type &value);
    template <uint m, uint n, typename type>
        matr_t<m, n, type> operator*(const type &value, const matr_t<m, n, type> &matr);
    template <uint m, uint n, typename type>
        matr_t<m, n, type> operator/(const matr_t<m, n, type> &matr, const type &value);
    template <uint n, typename type>
        matr_t<n, n, type> operator/(const type &value, const matr_t<n, n, type> &matr);
    // matrix by matrix multiply operators
    template <uint m, uint k, uint n, typename type>
        matr_t<m, n, type> operator*(const matr_t<m, k, type> &matr1, const matr_t<k, n, type> &matr2);
    template <uint n, typename type>
        matr_t<n, n, type> & operator*=(matr_t<n, n, type> &matr1, const matr_t<n, n, type> &matr2);
    // vector by matrix multiply operators
    template <uint m, uint n, typename type>
        vec_t<m, type> operator*(const matr_t<m, n, type> &matr, const vec_t<n, type> &vec);
    template <uint m, uint n, typename type>
        vec_t<n, type> operator*(const vec_t<m, type> &vec, const matr_t<m, n, type> &matr);
    template <uint n, typename type>
        vec_t<n, type> & operator*=(vec_t<n, type> &vec, const matr_t<n, n, type> &matr);
    // matrix division operators (multiply by invert) (left - matrix or vector)
    template <typename left_type, uint n, typename type>
        left_type operator/(const left_type &left, const matr_t<n, n, type> &matr);
    template <typename left_type, uint n, typename type>
        left_type & operator/=(left_type &left, const matr_t<n, n, type> &matr);
}

// iostream input/output definition
template <uint m, uint n, typename type>
    std::istream & operator>>(std::istream &is, mth::matr_t<m, n, type> &matr);
template <uint m, uint n, typename type>
    std::ostream & operator<<(std::ostream &os, const mth::matr_t<m, n, type> &matr);

#include "matr_imp.h"

#endif // _MATR_H_
