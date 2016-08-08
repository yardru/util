#ifdef _FIXED_H_

#ifndef _FIXED_IMP_H_
#define _FIXED_IMP_H_

#define FIXED_T fixed_t<n, type>

namespace def
{
    template <uint n, typename type>
        const type FIXED_T::_denominator = pow(10, n);
    // constructors
    template <uint n, typename type>
        FIXED_T::fixed_t()
        {
        }
    template <uint n, typename type>
        FIXED_T::fixed_t(const fixed_t &fixed) : _value(fixed._value)
        {
        }
    template <uint n, typename type>
        template <uint m>
            FIXED_T::fixed_t(const fixed_t<m, type> &fixed)
            {
                *this = fixed_t((double)fixed);
            }
    template <uint n, typename type>
        FIXED_T::fixed_t(int value) : _value(value * _denominator)
        {
        }
    template <uint n, typename type>
        FIXED_T::fixed_t(double value) : _value(value * _denominator)
        {
            if ((int)(value * _denominator * 10) % 10 >= 5)
                _value++;
        }
    // math operators
    template <uint n, typename type>
        FIXED_T & FIXED_T::operator+=(const FIXED_T &fixed)
        {
            _value += fixed._value;
            return *this;
        }
    template <uint n, typename type>
        FIXED_T & FIXED_T::operator-=(const FIXED_T &fixed)
        {
            _value -= fixed._value;
            return *this;
        }
    template <uint n, typename type>
        FIXED_T & FIXED_T::operator*=(const FIXED_T &fixed)
        {
            _value *= fixed._value;
            _value /= _denominator;
            return *this;
        }
    template <uint n, typename type>
        FIXED_T & FIXED_T::operator/=(const FIXED_T &fixed)
        {
            _value *= _denominator;
            _value /= fixed._value;
            return *this;
        }
    // type conversation
    template <uint n, typename type>
        FIXED_T::operator int() const
        {
            return _value / _denominator;
        }
    template <uint n, typename type>
        FIXED_T::operator double() const
        {
            return (double)_value / _denominator;
        }
    // order funcs
    template <uint n, typename type>
        bool FIXED_T::equal(const FIXED_T &fixed) const
        {
            return _value == fixed._value;
        }
    template <uint n, typename type>
        bool FIXED_T::less(const FIXED_T &fixed) const
        {
            return _value < fixed._value;
        }
    // order operators
    template <uint n, typename type>
        bool operator==(const FIXED_T &fixed1, const FIXED_T &fixed2)
        {
            return fixed1.equal(fixed2);
        }
    template <uint n, typename type>
        bool operator!=(const FIXED_T &fixed1, const FIXED_T &fixed2)
        {
            return !fixed1.equal(fixed2);
        }
    template <uint n, typename type>
        bool operator> (const FIXED_T &fixed1, const FIXED_T &fixed2)
        {
            return !fixed1.less(fixed2);
        }
    template <uint n, typename type>
        bool operator< (const FIXED_T &fixed1, const FIXED_T &fixed2)
        {
            return fixed1.less(fixed2);
        }
    template <uint n, typename type>
        bool operator>=(const FIXED_T &fixed1, const FIXED_T &fixed2)
        {
            return fixed2.less(fixed1);
        }
    template <uint n, typename type>
        bool operator<=(const FIXED_T &fixed1, const FIXED_T &fixed2)
        {
            return !fixed2.less(fixed1);
        }
    template <uint n, typename type>
        FIXED_T operator-(const FIXED_T &fixed)
        {
            return FIXED_T(fixed) *= -1;
        }
    template <uint n, typename type>
        FIXED_T operator+(const FIXED_T &fixed1, const FIXED_T &fixed2)
        {
            return FIXED_T(fixed1) += fixed2;
        }
    template <uint n, typename type>
        FIXED_T operator-(const FIXED_T &fixed1, const FIXED_T &fixed2)
        {
            return FIXED_T(fixed1) -= fixed2;
        }
    template <uint n, typename type>
        FIXED_T operator*(const FIXED_T &fixed1, const FIXED_T &fixed2)
        {
            return FIXED_T(fixed1) *= fixed2;
        }
    template <uint n, typename type>
        FIXED_T operator/(const FIXED_T &fixed1, const FIXED_T &fixed2)
        {
            return FIXED_T(fixed1) /= fixed2;
        }
}

// iostream input/output definition
template <uint n, typename type>
    std::istream & operator>>(std::istream &is, def::FIXED_T &fixed)
    {
        double tmp;
        is >> tmp;
        fixed = def::FIXED_T(tmp)
        return is;
    }
template <uint n, typename type>
    std::ostream & operator<<(std::ostream &os, const def::FIXED_T &fixed)
    {
        return os << (double)fixed;
    }

#endif // _FIXED_IMP_H_

#endif // _FIXED_H_
