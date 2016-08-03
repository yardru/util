#ifdef _COMP_H_

#ifndef _COMP_IMP_H_
#define _COMP_IMP_H_

#define COMP_T comp_t<type>

namespace mth
{
    // constructors
    template <typename type>
        COMP_T::comp_t() :
            re(_real), im(_imag), x(_real), y(_imag)
        {
        }
    template <typename type>
        COMP_T::comp_t(const COMP_T &comp) :
            re(_real), im(_imag), x(_real), y(_imag),
            _real(comp._real), _imag(comp._imag)
        {
        }
    template <typename type>
        COMP_T::comp_t(const type &real, const type &imag) :
            re(_real), im(_imag), x(_real), y(_imag),
            _real(real), _imag(imag)
        {
        }
    // math operators
    template <typename type>
        COMP_T & COMP_T::operator+=(const COMP_T &comp)
        {
            x += comp.x;
            y += comp.y;

            return *this;
        }
    template <typename type>
        COMP_T & COMP_T::operator-=(const COMP_T &comp)
        {
            x -= comp.x;
            y -= comp.y;

            return *this;
        }
    template <typename type>
        COMP_T & COMP_T::operator*=(const COMP_T &comp)
        {
            return *this = COMP_T(x * comp.x - y * comp.y, x * comp.y + y * comp.x);
        }
    template <typename type>
        COMP_T & COMP_T::operator/=(const COMP_T &comp)
        {
            *this *= !comp;
            x /= comp.abs();
            y /= comp.abs();

            return *this;
        }
    // other operators
    template <typename type>
        COMP_T & COMP_T::operator=(const COMP_T &comp)
        {
            x = comp.x;
            y = comp.y;

            return *this;
        }
    // math functions
    template <typename type>
        type COMP_T::abs()
        {
            return sqrt(sqr(x) + sqr(y));
        }
    template <typename type>
        type COMP_T::arg()
        {
            return atan2(im, re);
        }
    // math operators
    template <typename type>
        COMP_T operator-(const COMP_T &comp)
        {
            return COMP_T(-comp.x, -comp.y);
        }
    template <typename type>
        COMP_T operator!(const COMP_T &comp)
        {
            return COMP_T(comp.x, -comp.y);
        }
    template <typename type>
        COMP_T operator+(const COMP_T &comp1, const COMP_T &comp2)
        {
            return COMP_T(comp1) += comp2;
        }
    template <typename type>
        COMP_T operator-(const COMP_T &comp1, const COMP_T &comp2)
        {
            return COMP_T(comp1) -= comp2;
        }
    template <typename type>
        COMP_T operator*(const COMP_T &comp1, const COMP_T &comp2)
        {
            return COMP_T(comp1) *= comp2;
        }
    template <typename type>
        COMP_T operator/(const COMP_T &comp1, const COMP_T &comp2)
        {
            return COMP_T(comp1) /= comp2;
        }
    // order operators
    template <typename type>
        bool operator==(const COMP_T &comp1, const COMP_T &comp2)
        {
            return (comp1.x == comp2.x) && (comp1.y == comp2.y);
        }
    template <typename type>
        bool operator!=(const COMP_T &comp1, const COMP_T &comp2)
        {
            return !(comp1 == comp2);
        }
}

// absolute comlex number value
template <typename type>
    type abs(const mth::COMP_T &comp)
    {
        return comp.abs();
    }

// iostream input/output definition
template <typename type>
    std::istream & operator>>(std::istream &is, mth::COMP_T &comp)
    {
        return is;
    }
template <typename type>
    std::ostream & operator<<(std::ostream &os, const mth::COMP_T &comp)
    {
        if (comp.x)
        {
            os << comp.x;
            if (comp.y > 0)
                os << " + " << comp.y << "i";
            else if (comp.y < 0)
                os << " - " << -comp.y << "i";
        }
        else
            if (comp.y)
                os << comp.y << "i";

        return os;
    }

#endif // _COMP_IMP_H_

#endif // _COMP_H_
