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
            matr_t & clone(const matr_t &);
        public:
            // get random matrix
            static matr_t rand(const type & = type(0), const type & = type(1));
            // constructors
            matr_t();
            matr_t(const matr_t &);
            matr_t(const type &);
            matr_t(const type *);
            matr_t(const type **);
            matr_t(type, type, ...);
            // math operators
            matr_t & operator+=(const matr_t &);
            matr_t & operator-=(const matr_t &);
            matr_t & operator*=(const type &);
            matr_t & operator/=(const type &);
            // other operators
            matr_t & operator=(const matr_t &);
            type & operator()(uint, uint);
            type operator()(uint, uint) const;
            type * operator[](uint);
            const type * operator[](uint) const;
            // setters
            matr_t & set(const matr_t &);
            matr_t & set(const type &);
            matr_t & set(const type *);
            matr_t & set(const type **);
            matr_t & set(type, type, ...);
            // setters/getters for rows and columns
            matr_t & set_row(uint, const type &);
            matr_t & set_row(uint, const type *);
            type * get_row(uint, type *) const;
            type * get_row(uint);
            matr_t & set_col(uint, const type &);
            matr_t & set_col(uint, const type *);
            type * get_col(uint, type *) const;
            // transpose matrix
            matr_t<n, m, type> transposing() const; // to other
            // elementary operations
            matr_t & row_mul(uint, const type &);  // multiply row by number
            matr_t & row_add_to(uint, const uint,
                const type & = type(1));           // add scaled second row to first
            matr_t & row_swap(uint, uint);         // swap two rows
            matr_t & col_mul(uint, const type &);  // multiply column by number
            matr_t & col_add_to(uint, const uint,
                const type & = type(1));           // add scaled second column to first
            matr_t & col_swap(uint, uint);         // swap two columns
            // math functions for square matrix
            matr_t & transpose();
            type trace() const;
            matr_t<n - 1, n - 1, type> minor(uint, uint) const;
            type cofactor(uint, uint) const;
            type det() const;
            matr_t & invert();
            matr_t inverting() const;
        };

    // transpose to other matrix functions
    template <uint m, uint n, typename type>
        matr_t<n, m, type> transposing(const matr_t<m, n, type> &);
    // functions for square matrix
    template <uint n, typename type>
        matr_t<n, n, type> & transpose(matr_t<n, n, type> &);
    template <uint n, typename type>
        matr_t<n - 1, n - 1, type> minor(const matr_t<n, n, type> &, uint, uint);
    template <uint n, typename type>
        type det(const matr_t<n, n, type> &);
    template <uint n, typename type>
        type cofactor(const matr_t<n, n, type> &, uint, uint);
    template <uint n, typename type>
        type trace(const matr_t<n, n, type> &);
    template <uint n, typename type>
        matr_t<n, n, type> inverting(const matr_t<n, n, type> &);
    template <uint n, typename type>
        matr_t<n, n, type> & invert(matr_t<n, n, type> &);
    template <uint n, typename type>
        matr_t<n, n, type> inv(const matr_t<n, n, type> &); // same as inverting
    // matrix simple math operators
    template <uint m, uint n, typename type>
        matr_t<m, n, type> operator-(const matr_t<m, n, type> &);
    template <uint m, uint n, typename type>
        matr_t<m, n, type> operator+(const matr_t<m, n, type> &, const matr_t<m, n, type> &);
    template <uint m, uint n, typename type>
        matr_t<m, n, type> operator-(const matr_t<m, n, type> &, const matr_t<m, n, type> &);
    template <uint m, uint n, typename type>
        matr_t<m, n, type> operator*(const matr_t<m, n, type> &, const type &);
    template <uint m, uint n, typename type>
        matr_t<m, n, type> operator*(const type &, const matr_t<m, n, type> &);
    template <uint m, uint n, typename type>
        matr_t<m, n, type> operator/(const matr_t<m, n, type> &, const type &);
    template <uint n, typename type>
        matr_t<n, n, type> operator/(const type &, const matr_t<n, n, type> &);
    // matrix by matrix multiply operators
    template <uint m, uint k, uint n, typename type>
        matr_t<m, n, type> operator*(const matr_t<m, k, type> &, const matr_t<k, n, type> &);
    template <uint n, typename type>
        matr_t<n, n, type> & operator*=(matr_t<n, n, type> &, const matr_t<n, n, type> &);
    // vector by matrix multiply operators
    template <uint m, uint n, typename type>
        vec_t<m, type> operator*(const matr_t<m, n, type> &, const vec_t<n, type> &);
    template <uint m, uint n, typename type>
        vec_t<n, type> operator*(const vec_t<m, type>&, const matr_t<m, n, type> &);
    template <uint n, typename type>
        vec_t<n, type> & operator*=(vec_t<n, type> &, const matr_t<n, n, type> &);
    // matrix division operators (multiply by invert)
    template <typename left_type, uint n, typename type>
        left_type operator/(const left_type &, const matr_t<n, n, type> &);
    template <typename left_type, uint n, typename type>
        left_type & operator/=(left_type &, const matr_t<n, n, type> &);
}

#include "matr_imp.h"

#endif // _MATR_H_
