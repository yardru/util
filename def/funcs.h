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

    // swap two arrays
    template<typename type>
        void swap(type *a, type *b, uint n = 1)
        {
            for (uint i = 0; i < n; i++)
                swap(a[i], b[i]);
        }

    // copy one array to another
    template<typename type>
        void copy(type *to, const type *from, uint n = 1)
        {
            for (uint i = 0; i < n; i++)
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

    // minimum in array
    template<typename type>
        type min(const type *a, uint n)
        {
            type res = a[0];
            for (int i = 1; i < n; i++)
                res = min(res, a[i]);
            return res;
        }

    // maximum in array
    template<typename type>
        type max(const type *a, uint n)
        {
            type res = a[0];
            for (int i = 1; i < n; i++)
                res = max(res, a[i]);
            return res;
        }
}

#endif // _FUNCS_H_
