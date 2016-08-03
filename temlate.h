#ifndef _TEMPLATE_H_
#define _TEMPLATE_H_

#include "def.h"
// "template_imp.h" file included in the end of file

namespace mth
{
    /* template class
     *     m - rows number (i changes)
     *     n - columns number (j changes)
     *     type - component type
     */
    template <typename type>
        class template_t
        {
        public:
            // constructors
            template_t();
            template_t(const template_t &);
        };
}

// iostream input/output definition
template <typename type>
    std::istream & operator>>(std::istream &is, mth::template_t<type> &);
template <typename type>
    std::ostream & operator<<(std::ostream &os, const mth::template_t<type> &);

#include "template_imp.h"

#endif // _TEMPLATE_H_
