#ifndef _MTH_H_
#define _MTH_H_

#include "def.h"
#include "comp.h"
#include "vec.h"
#include "matr.h"

namespace mth
{
    typedef comp_t<> comp;

    typedef vec_t<2> vec2;
    typedef vec_t<3> vec3;
    typedef vec_t<4> vec4;

    typedef matr_t<2, 2> matr22;
    typedef matr_t<2, 3> matr23;
    typedef matr_t<2, 4> matr24;
    typedef matr_t<3, 2> matr32;
    typedef matr_t<3, 3> matr33;
    typedef matr_t<3, 4> matr34;
    typedef matr_t<4, 2> matr42;
    typedef matr_t<4, 3> matr43;
    typedef matr_t<4, 4> matr44;

    typedef matr22 smatr2;
    typedef smatr2 matr2;

    typedef matr33 smatr3;
    typedef smatr3 matr3;

    typedef matr44 smatr4;
    typedef smatr4 matr4;
}

#endif // _MTH_H_
