#ifdef _MATR_H_

#ifndef _MATR_IMP_H_
#define _MATR_IMP_H_

#define MATR_T matr_t<m, n, type>
#define SMATR_T matr_t<n, n, type>

namespace mth
{
    // make copy of the matrix
    template <uint m, uint n, typename type>
        MATR_T & MATR_T::clone(const MATR_T &matr)
        {
            def::copy_mass(_components, matr._components, m * n);

            return *this;
        }
    // get random matrix
    template <uint m, uint n, typename type>
        static MATR_T MATR_T::rand(const type &min, const type &max)
        {
            MATR_T res;
            return res;
        }
    // constructors
    template <uint m, uint n, typename type>
        MATR_T::matr_t()
        {
        }
    template <uint m, uint n, typename type>
        MATR_T::matr_t(const MATR_T &matr)
        {
            set(matr);
        }
    template <uint m, uint n, typename type>
        MATR_T::matr_t(const type &value)
        {
            set(value);
        }
    template <uint m, uint n, typename type>
        MATR_T::matr_t(const type *values)
        {
            set(values);
        }
    template <uint m, uint n, typename type>
        MATR_T::matr_t(const type **values)
        {
            set(values);
        }
    template <uint m, uint n, typename type>
        MATR_T::matr_t(type value1, type value2, ...)
        {
            _components[0] = value1;
            _components[1] = value2;
            va_list args;
            va_start(args, value2);
            for (uint i = 2; i < m * n; i++)
                _components[i] = va_arg(args, type);
            va_end(args);
        }
    // math operators
    template <uint m, uint n, typename type>
        MATR_T & MATR_T::operator+=(const MATR_T &matr)
        {
            for (uint i = 0; i < m * n; i++)
                _components[i] += matr._components[i];

            return *this;
        }
    template <uint m, uint n, typename type>
        MATR_T & MATR_T::operator-=(const MATR_T &matr)
        {
            for (uint i = 0; i < m * n; i++)
                _components[i] -= matr._components[i];

            return *this;
        }
    template <uint m, uint n, typename type>
        MATR_T & MATR_T::operator*=(const type &value)
        {
            for (uint i = 0; i < m * n; i++)
                _components[i] *= value;

            return *this;
        }
    template <uint m, uint n, typename type>
        MATR_T & MATR_T::operator/=(const type &value)
        {
            for (uint i = 0; i < m * n; i++)
                _components[i] /= value;

            return *this;
        }
    // other operators
    template <uint m, uint n, typename type>
        MATR_T & MATR_T::operator=(const MATR_T &matr)
        {
            return this->clone(matr);
        }
    template <uint m, uint n, typename type>
        type & MATR_T::operator()(uint i, uint j)
        {
            return _components[i * n + j];
        }
    template <uint m, uint n, typename type>
        type MATR_T::operator()(uint i, uint j) const
        {
            return _components[i * n + j];
        }
    template <uint m, uint n, typename type>
        type * MATR_T::operator[](uint i)
        {
            return _components + i * n;
        }
    template <uint m, uint n, typename type>
        const type * MATR_T::operator[](uint i) const
        {
            return _components + i * n;
        }
    // setters
    template <uint m, uint n, typename type>
        MATR_T & MATR_T::set(const MATR_T &matr)
        {
            return this->clone(matr);
        }
    template <uint m, uint n, typename type>
        MATR_T & MATR_T::set(const type &value)
        {
            for (uint i = 0; i < m; i++)
                for (uint j = 0; j < n; j++)
                    _components[i * n + j] = value * (i == j);

            return *this;
        }
    template <uint m, uint n, typename type>
        MATR_T & MATR_T::set(const type *values)
        {
            def::copy_mass(_components, values);

            return *this;
        }
    template <uint m, uint n, typename type>
        MATR_T & MATR_T::set(const type **values)
        {
            for (uint i = 0; i < m; i++)
                def::copy_mass(_components + i * n, values[i]);

            return *this;
        }
    template <uint m, uint n, typename type>
        MATR_T & MATR_T::set(type value1, type value2, ...)
        {
            _components[0] = value1;
            _components[1] = value2;
            va_list args;
            va_start(args, value2);
            for (uint i = 2; i < m * n; i++)
                _components[i] = va_arg(args, type);
            va_end(args);

            return *this;
        }
    // setters/getters for rows and columns
    template <uint m, uint n, typename type>
        MATR_T & MATR_T::set_row(uint i, const type &value)
        {
            for (uint j = 0; j < n; j++)
                (*this)[i][j] = value;

            return *this;
        }
    template <uint m, uint n, typename type>
        MATR_T & MATR_T::set_row(uint i, const type *values)
        {
            for (uint j = 0; j < n; j++)
                (*this)[i][j] = values[j];

            return *this;
        }
    template <uint m, uint n, typename type>
        type * MATR_T::get_row(uint i, type *to) const
        {
            if (to == NULL)
                return NULL;

            for (uint j = 0; j < n; j++)
                to[j] = (*this)[i][j];

            return to;
        }
    template <uint m, uint n, typename type>
        type * MATR_T::get_row(uint i)
        {
            return (*this)[i];
        }
    template <uint m, uint n, typename type>
        MATR_T & MATR_T::set_col(uint j, const type &value)
        {
            for (uint i = 0; i < m; i++)
                (*this)[i][j] = value;

            return *this;
        }
    template <uint m, uint n, typename type>
        MATR_T & MATR_T::set_col(uint j, const type *values)
        {
            for (uint i = 0; i < m; i++)
                (*this)[i][j] = values[i];

            return *this;
        }
    template <uint m, uint n, typename type>
        type * MATR_T::get_col(uint j, type *to) const
        {
            if (to == NULL)
                return NULL;

            for (uint i = 0; i < m; i++)
                to[i] = (*this)[i][j];

            return to;
        }
    // transpose matrix
    template <uint m, uint n, typename type>
        matr_t<n, m, type> MATR_T::transposing() const
        {
            return mth::transposing(*this);
        }
    // elementary operations
    template <uint m, uint n, typename type>
        MATR_T & MATR_T::row_mul(uint i, const type &value)
        {
            for (uint j = 0; j < n; j++)
                (*this)[i][j] *= value;

            return *this;
        }
    template <uint m, uint n, typename type>
        MATR_T & MATR_T::row_add_to(uint i_to, const uint i_from, const type &s)
        {
            for (uint j = 0; j < n; j++)
                (*this)[i_to][j] += (*this)[i_from][j] * s;

            return *this;
        }
    template <uint m, uint n, typename type>
        MATR_T & MATR_T::row_swap(uint i1, uint i2)
        {
            for (uint j = 0; j < n; j++)
                swap((*this)[i1][j], (*this)[i2][j]);

            return *this;
        }
    template <uint m, uint n, typename type>
        MATR_T & MATR_T::col_mul(uint j, const type &value)
        {
            for (uint i = 0; i < m; i++)
                (*this)[i][j] *= value;

            return *this;
        }
    template <uint m, uint n, typename type>
        MATR_T & MATR_T::col_add_to(uint j_to, const uint j_from, const type &s)
        {
            for (uint i = 0; i < m; i++)
                (*this)[i][j_to] += (*this)[i][j_from] * s;

            return *this;
        }
    template <uint m, uint n, typename type>
        MATR_T & MATR_T::col_swap(uint j1, uint j2)
        {
            for (uint i = 0; i < m; i++)
                swap((*this)[i][j1], (*this)[i][j2]);

            return *this;
        }

    // math functions for square matrix
    template <uint m, uint n, typename type>
        MATR_T & MATR_T::transpose()
        {
            return mth::transpose(*this);
        }
    template <uint m, uint n, typename type>
        type MATR_T::trace() const
        {
            return mth::trace(*this);
        }
    template <uint m, uint n, typename type>
        matr_t<n - 1, n - 1, type> MATR_T::minor(uint, uint) const
        {
            return mth::minor(*this);
        }
    template <uint m, uint n, typename type>
        type MATR_T::cofactor(uint, uint) const
        {
            return mth::cofactor(*this);
        }
    template <uint m, uint n, typename type>
        type MATR_T::det() const
        {
            return mth::det(*this);
        }
    template <uint m, uint n, typename type>
        MATR_T & MATR_T::invert()
        {
            return mth::invert(*this);
        }
    template <uint m, uint n, typename type>
        MATR_T MATR_T::inverting() const
        {
            return mth::inv(*this);
        }
    // transpose to other matrix functions
    template <uint m, uint n, typename type>
        matr_t<n, m, type> transposing(const MATR_T &matr)
        {
            matr_t<n, m, type> r;

            for (uint j = 0; j < n; j++)
                matr.get_col(j, r.get_row(j));

            return r;
        }
    template <uint m, uint n, typename type>
        matr_t<n, m, type> trans(const MATR_T &matr)
        {
            return transposing(matr);
        }
    // functions for square matrix
    template <uint n, typename type>
        SMATR_T & transpose(SMATR_T &matr)
        {
            for (uint i = 0; i < n; i++)
                for (uint j = i + 1; j < n; j++)
                    swap(matr[i][j], matr[j][i]);

            return matr;
        }
    template <uint n, typename type>
        matr_t<n - 1, n - 1, type> minor(const matr_t<n, n, type> &matr, uint i, uint j)
        {
            matr_t<n - 1, n - 1, type> res;

            for (uint ci = 0; ci < n - 1; ci++)
                for (uint cj = 0; cj < n - 1; cj++)
                    res[ci][cj] = matr[ci + (ci >= i)][cj + (cj >= j)];

            return res;
        }
    template <uint n, typename type>
        type triangle_det(const SMATR_T &matr)
        {
            SMATR_T tmp(matr);
            type r = 1;

            for (uint i = 0; i < n; i++)
            {
                uint k = -1;
                for (uint j = i; j < n; j++)
                    if (tmp[j][i] != 0)
                    {
                        k = j;
                        break;
                    }
                if (k < 0)
                    return 0;
                if (k > i)
                {
                    tmp.row_swap(i, k);
                    r *= -1;
                }

                for (uint j = k + 1; j < n; j++)
                {
                    type s = tmp[j][i];
                    tmp.row_mul(j, tmp[i][i]);
                    tmp.row_add_to(j, i, -s);
                    tmp.row_mul(j, 1 / tmp[i][i]);
                }
            }

            for (uint i = 0; i < n; i++)
                r *= tmp[i][i];

            return r;
        }
    template <uint n, typename type>
        type det(const SMATR_T &matr)
        {
            type r = 0;
            for (int i = 0; i < n; i++)
                r += matr[0][i] * cofactor(matr, 0, i);

            return r;
        }
    template <typename type>
        type det(const matr_t<1, 1, type> &matr)
        {
            return matr[0][0];
        }
    template <typename type>
        type det(const matr_t<2, 2, type> &matr)
        {
            return matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];
        }
    template <typename type>
        type det(const matr_t<3, 3, type> &matr)
        {
            return matr[0][0] * (matr[1][1] * matr[2][2] - matr[1][2] * matr[2][1]) +
                   matr[0][1] * (matr[1][2] * matr[2][0] - matr[1][0] * matr[2][2]) +
                   matr[0][2] * (matr[1][0] * matr[2][1] - matr[1][1] * matr[2][0]);
        }
    template <typename type>
        type det(const matr_t<4, 4, type> &matr)
        {
            type m0, m1, m2, m3; // minors

            m0 = matr[1][1] * (matr[2][2] * matr[3][3] - matr[2][3] * matr[3][2]) +
                 matr[1][2] * (matr[2][3] * matr[3][1] - matr[2][1] * matr[3][3]) +
                 matr[1][3] * (matr[2][1] * matr[3][2] - matr[2][2] * matr[3][1]);

            m1 = matr[1][0] * (matr[2][2] * matr[3][3] - matr[2][3] * matr[3][2]) +
                 matr[1][2] * (matr[2][3] * matr[3][0] - matr[2][0] * matr[3][3]) +
                 matr[1][3] * (matr[2][0] * matr[3][2] - matr[2][2] * matr[3][0]);

            m2 = matr[1][0] * (matr[2][1] * matr[3][3] - matr[2][3] * matr[3][1]) +
                 matr[1][1] * (matr[2][3] * matr[3][0] - matr[2][0] * matr[3][3]) +
                 matr[1][3] * (matr[2][0] * matr[3][1] - matr[2][1] * matr[3][0]);

            m3 = matr[1][0] * (matr[2][1] * matr[3][2] - matr[2][2] * matr[3][1]) +
                 matr[1][1] * (matr[2][2] * matr[3][0] - matr[2][0] * matr[3][2]) +
                 matr[1][2] * (matr[2][0] * matr[3][1] - matr[2][1] * matr[3][0]);

            return matr[0][0] * m0 - matr[0][1] * m1 + matr[0][2] * m2 - matr[0][3] * m3;
        }
    template <uint n, typename type>
        type cofactor(const SMATR_T &matr, uint i, uint j)
        {
            return (type((i + j + 1) % 2) * 2 - 1) * det(minor(matr, i, j));
        }

    template <uint n, typename type>
        type trace(const SMATR_T &matr)
        {
            type r = 0;
            for (uint i = 0; i < n; i++)
                r += matr[i][i];

            return r;
        }
    template <uint n, typename type>
        SMATR_T inverting(const SMATR_T &matr)
        {
            return inv(matr);
        }
    template <uint n, typename type>
        SMATR_T & invert(matr_t<n, n, type> &matr)
        {
            return matr = inv(matr);
        }
    template <uint n, typename type>
        SMATR_T inv(const matr_t<n, n, type> &matr)
        {
            SMATR_T res;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i][j] = cofactor(matr, j, i);

            return res /= det(matr);
        }
    // matrix simple math operators
    template <uint m, uint n, typename type>
        MATR_T operator-(const MATR_T &matr)
        {
            return MATR_T(matr) *= -1;
        }
    template <uint m, uint n, typename type>
        MATR_T operator+(const MATR_T &matr1, const MATR_T &matr2)
        {
            return MATR_T(matr1) += matr2;
        }
    template <uint m, uint n, typename type>
        MATR_T operator-(const MATR_T &matr1, const MATR_T &matr2)
        {
            return MATR_T(matr1) -= matr2;
        }
    template <uint m, uint n, typename type>
        MATR_T operator*(const MATR_T &matr, const type &value)
        {
            return MATR_T(matr) *= value;
        }
    template <uint m, uint n, typename type>
        MATR_T operator*(const type &value, const MATR_T &matr)
        {
            return MATR_T(matr) *= value;
        }
    template <uint m, uint n, typename type>
        MATR_T operator/(const MATR_T &matr, const type &value)
        {
            return MATR_T(matr) /= value;
        }
    template <uint n, typename type>
        SMATR_T operator/(const type &value, const SMATR_T &matr)
        {
            return value * inv(matr);
        }
    // matrix by matrix multiply operators
    template <uint m, uint k, uint n, typename type>
        matr_t<m, n, type> operator*(const matr_t<m, k, type> &matr1, const matr_t<k, n, type> &matr2)
        {
            matr_t<m, n, type> res(type(0));

            for (uint i = 0; i < m; i++)
                for (uint j = 0; j < n; j++)
                    for (uint l = 0; l < k; l++)
                        res[i][j] += matr1[i][l] * matr2[l][j];

            return res;
        }
    template <uint n, typename type>
        matr_t<n, n, type> & operator*=(matr_t<n, n, type> &matr1, const matr_t<n, n, type> &matr2)
        {
            return matr1 = matr1 * matr2;
        }
    // vector by matrix multiply operators
    template <uint m, uint n, typename type>
        vec_t<m, type> operator*(const matr_t<m, n, type> &matr, const vec_t<n, type> &vec)
        {
            vec_t<m, type> res(type(0));

            for (uint i = 0; i < m; i++)
                for (uint j = 0; j < n; j++)
                    res[i] += matr[i][j] * vec[j];

            return res;
        }
    template <uint m, uint n, typename type>
        vec_t<n, type> operator*(const vec_t<m, type> &vec, const matr_t<m, n, type> &matr)
        {
            return matr * vec;
        }
    template <uint n, typename type>
        vec_t<n, type> & operator*=(vec_t<n, type> &vec, const SMATR_T &matr)
        {
            return vec = vec * matr;
        }
    // matrix division operators (multiply by invert) for matrix and vectors
    template <typename left_type, uint n, typename type>
        left_type operator/(const left_type &left, const SMATR_T &matr)
        {
            return left * inv(matr);
        }
    template <typename left_type, uint n, typename type>
        left_type & operator/=(left_type &left, const SMATR_T &matr)
        {
            return left = left * inv(matr);
        }

}

// iostream input/output definition
template <uint m, uint n, typename type>
    std::istream & operator>>(std::istream &is, mth::MATR_T &matr)
    {
        return is;
    }
template <uint m, uint n, typename type>
    std::ostream & operator<<(std::ostream &os, const mth::MATR_T &matr)
    {
        for (uint i = 0; i < m; i++)
        {
            if (i == 0)
                if (i == m - 1)
                    os << "(";
                else
                    os << "/";
            else
                if (i == m - 1)
                    os << "\\";
                else
                    os << "|";
            os << matr[i][0];

            for (uint j = 1; j < n; j++)
                os << " " << matr[i][j];

            if (i == 0)
                if (i == m - 1)
                    os << ")";
                else
                    os << "\\";
            else
                if (i == m - 1)
                    os << "/";
                else
                    os << "|";
            os << "\n";
        }

        return os;
    }

#endif // _MATR_IMP_H_

#endif // _MATR_H_
