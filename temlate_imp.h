#ifdef _TEMPLATE_H_

#ifndef _TEMPLATE_IMP_H_
#define _TEMPLATE_IMP_H_

#define TEMPLATE_T template_t<type>

// iostream input/output definition
template <typename type>
    std::istream & operator>>(std::istream &is, mth::TEMPLATE_T &template)
    {
        return is;
    }
template <typename type>
    std::ostream & operator<<(std::ostream &os, const mth::TEMPLATE_T &template)
    {
        return os << "this is template!!!\n";
    }

#endif // _TEMPLATE_IMP_H_

#endif // _TEMPLATE_H_
