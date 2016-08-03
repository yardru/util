#ifndef _FUNCS_H_
#define _FUNCS_H_

namespace def
{
    /// TODO in lib
    static double _treshold = 0.0000000000001;

    __inline double set_treshold(double treshold)
        {
            double old = _treshold;
            _treshold = treshold;
            return old;
        }

    __inline double get_treshold()
        {
            return _treshold;
        }

    // swap two argument
    template<typename type>
        void swap(type &a, type &b)
        {
            type tmp = a;
            a = b;
            b = tmp;
        }

    // swap two massive
    template<typename type>
        void swap_mass(type *a, type *b, int n)
        {
            for (int i = 0; i < n; i++)
                swap(a[i], b[i]);
        }

    // copy one massive to another
    template<typename type>
        void copy_mass(type *to, const type *from, int n)
        {
            for (int i = 0; i < n; i++)
                to[i] = from[i];
        }

    // minimum of two argument
    template<typename type>
        type min(const type &a, const type &b)
        {
            return (a < b) ? a : b;
        }

    // maximum of two argument
    template<typename type>
        type max(const type &a, const type &b)
        {
            return (a > b) ? a : b;
        }
}

#endif // _FUNCS_H_
