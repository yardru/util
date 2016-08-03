#ifdef _VEC_H_

#ifndef _VEC_IMP_H_
#define _VEC_IMP_H_

#include <stdarg.h>

#define VEC_T vec_t<n, type>

namespace mth
{
    // make copy of the vector
    template <uint n, typename type>
        VEC_T & VEC_T::clone(const VEC_T &vec)
        {
            def::copy_mass(_components, vec._components, n);

            return *this;
        }
    // constructors
    template <uint n, typename type>
        VEC_T::vec_t() :
            x(_components[0]), y(_components[1]), z(_components[2]), w(_components[3]),
            r(_components[0]), g(_components[1]), b(_components[2]), a(_components[3]),
            s(_components[0]), t(_components[1]), p(_components[2]), q(_components[3])
        {
        }
    template <uint n, typename type>
        VEC_T::vec_t(const vec_t &vec) :
            x(_components[0]), y(_components[1]), z(_components[2]), w(_components[3]),
            r(_components[0]), g(_components[1]), b(_components[2]), a(_components[3]),
            s(_components[0]), t(_components[1]), p(_components[2]), q(_components[3])
        {
            set(vec);
        }
    template <uint n, typename type>
        VEC_T::vec_t(const type *values) :
            x(_components[0]), y(_components[1]), z(_components[2]), w(_components[3]),
            r(_components[0]), g(_components[1]), b(_components[2]), a(_components[3]),
            s(_components[0]), t(_components[1]), p(_components[2]), q(_components[3])
        {
            set(values);
        }
    template <uint n, typename type>
        VEC_T::vec_t(const type &value) :
            x(_components[0]), y(_components[1]), z(_components[2]), w(_components[3]),
            r(_components[0]), g(_components[1]), b(_components[2]), a(_components[3]),
            s(_components[0]), t(_components[1]), p(_components[2]), q(_components[3])
        {
            set(value);
        }
    template <uint n, typename type>
        VEC_T::vec_t(type value1, type value2, ...) :
            x(_components[0]), y(_components[1]), z(_components[2]), w(_components[3]),
            r(_components[0]), g(_components[1]), b(_components[2]), a(_components[3]),
            s(_components[0]), t(_components[1]), p(_components[2]), q(_components[3])
        {
            _components[0] = value1;
            _components[1] = value2;
            va_list args;
            va_start(args, value2);
            for (int i = 2; i < n; i++)
                _components[i] = va_arg(args, type);
            va_end(args);
        }
    // math operators
    template <uint n, typename type>
        VEC_T & VEC_T::operator+=(const VEC_T &vec)
        {
            for (int i = 0; i < n; i++)
                _components[i] += vec._components[i];

            return *this;
        }
    template <uint n, typename type>
        VEC_T & VEC_T::operator-=(const VEC_T &vec)
        {
            for (int i = 0; i < n; i++)
                _components[i] -= vec._components[i];

            return *this;
        }
    template <uint n, typename type>
        VEC_T & VEC_T::operator*=(const type &value)
        {
            for (int i = 0; i < n; i++)
                _components[i] *= value;

            return *this;
        }
    template <uint n, typename type>
        VEC_T & VEC_T::operator*=(const VEC_T &vec)
        {
            for (int i = 0; i < n; i++)
                _components[i] *= vec._components[i];

            return *this;
        }
    template <uint n, typename type>
        VEC_T & VEC_T::operator/=(const type &value)
        {
            for (int i = 0; i < n; i++)
                _components[i] /= value;

            return *this;
        }
    template <uint n, typename type>
        VEC_T & VEC_T::operator/=(const VEC_T &vec)
        {
            for (int i = 0; i < n; i++)
                _components[i] /= vec._components[i];

            return *this;
        }
    // other operators
    template <uint n, typename type>
        VEC_T & VEC_T::operator=(const VEC_T &vec)
        {
            return this->clone(vec);
        }
    template <uint n, typename type>
        type & VEC_T::operator[](uint index)
        {
            return _components[index];
        }
    template <uint n, typename type>
        type VEC_T::operator[](uint index) const
        {
            return _components[index];
        }
    // setters
    template <uint n, typename type>
        VEC_T & VEC_T::set(const VEC_T &vec)
        {
            return this->clone(vec);
        }
    template <uint n, typename type>
        VEC_T & VEC_T::set(const type *values)
        {
            def::copy_mass(_components, values, n);

            return *this;
        }
    template <uint n, typename type>
        VEC_T & VEC_T::set(const type &value)
        {
            for (int i = 0; i < n; i++)
                _components[i] = value;

            return *this;
        }
    template <uint n, typename type>
        VEC_T & VEC_T::set(type value1, type value2, ...)
        {
            _components[0] = value1;
            _components[1] = value2;
            va_list args;
            va_start(args, value2);
            for (int i = 2; i < n; i++)
                _components[i] = va_arg(args, type);
            va_end(args);

            return *this;
        }
    // get vector lenght
    template <uint n, typename type>
        type VEC_T::lenght() const
        {
            type res = 0;
            for (int i = 0; i < n; i++)
                res += sqr(_components[i]);

            return sqrt(res);
        }
    // normalize vector
    template <uint n, typename type>
        VEC_T & VEC_T::normalize()
        {
            type del = lenght();
            if (del)
                *this /= del;

            return *this;
        }
    template <uint n, typename type>
        VEC_T VEC_T::normalizing() const
        {
            return VEC_T(*this).normalizing();
        }
    // math operators
    template <uint n, typename type>
        VEC_T operator-(const VEC_T &vec)
        {
            return VEC_T(vec) *= -1;
        }
    template <uint n, typename type>
        VEC_T operator+(const VEC_T &vec1, const VEC_T &vec2)
        {
            return VEC_T(vec1) += vec2;
        }
    template <uint n, typename type>
        VEC_T operator-(const VEC_T &vec1, const VEC_T &vec2)
        {
            return VEC_T(vec1) -= vec2;
        }
    template <uint n, typename type>
        VEC_T operator*(const VEC_T &vec, const type &value)
        {
            return VEC_T(vec) *= value;
        }
    template <uint n, typename type>
        VEC_T operator*(const type &value, const VEC_T &vec)
        {
            return VEC_T(vec) *= value;
        }
    template <uint n, typename type>
        VEC_T operator*(const VEC_T &vec1, const VEC_T &vec2)
        {
            return VEC_T(vec1) *= vec2;
        }
    template <uint n, typename type>
        type  operator&(const VEC_T &vec1, const VEC_T &vec2)
        {
            type res = 0;
            for (int i = 0; i < n; i++)
                res += vec1[i] * vec2[i];
            return res;
        }
    template <uint n, typename type>
        VEC_T operator/(const VEC_T &vec, const type &value)
        {
            return VEC_T(vec) /= value;
        }
    template <uint n, typename type>
        VEC_T operator/(const type &value, const VEC_T &vec)
        {
            return VEC_T(vec) /= value;
        }
    template <uint n, typename type>
        VEC_T operator/(const VEC_T &vec1, const VEC_T &vec2)
        {
            return VEC_T(vec1) /= vec2;
        }
    // order operators
    template <uint n, typename type>
        bool operator==(const VEC_T &vec1, const VEC_T &vec2)
        {
            for (int i = 0; i < n; i++)
                if (abs(vec1[i] - vec2[i]) > def::get_treshold())
                    return false;

            return true;
        }
    template <uint n, typename type>
        bool operator!=(const VEC_T &vec1, const VEC_T &vec2)
        {
            return !(vec1 == vec2);
        }
    // cross product operator for 3d vectors
    template <typename type>
        vec_t<3, type> & operator%=(vec_t<3, type> &vec1, const vec_t<3, type> &vec2)
        {
            return vec1.set(vec1.y * vec2.z - vec1.z * vec2.y,
                            vec1.z * vec2.x - vec1.x * vec2.z,
                            vec1.x * vec2.y - vec1.y * vec2.x);
        }
    template <typename type>
        vec_t<3, type> operator%(const vec_t<3, type> &vec1, const vec_t<3, type> &vec2)
        {
            return vec_t<3, type>(vec1.y * vec2.z - vec1.z * vec2.y,
                                  vec1.z * vec2.x - vec1.x * vec2.z,
                                  vec1.x * vec2.y - vec1.y * vec2.x);
            //return vec_t<type, 3>(vec1) %= vec2;
        }
}

// vector absolut value
template <uint n, typename type>
    type abs(const mth::VEC_T &vec)
    {
        return vec.lenght();
    }
// iostream input/output definition
template <uint n, typename type>
    std::istream & operator>>(std::istream &is, mth::VEC_T &vec)
    {
        return is;
    }
template <uint n, typename type>
    std::ostream & operator<<(std::ostream &os, const mth::VEC_T &vec)
    {
        os << "(" << vec[0];

        for (int i = 1; i < n; i++)
            os << ", " << vec[i];

        return os << ")";
    }

#endif // _VEC_IMP_H_

#endif // _VEC_H_
