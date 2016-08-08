#include <iostream>
#include <string>
#include <time.h>

#include <mth/mth.h>

using namespace std;
using namespace mth;

void comp_test()
{
    cout << "test1: " << comp(0, 1) << "\n";
    cout << "test2: " << sqr(comp(0, 1)) << "\n";
    cout << "test3: " << comp(1, 1) << "\n";
}

void vec_test()
{
    vec3 v1(1.0, 2.0, 2.0), v2(0.0, -1.0, -1.0),
         v3(2.0, 0.0, 0.0), v4(0.0, -1.0, 0.0);

    cout << "v1: " << v1 << "\n";
    cout << "v2: " << v2 << "\n";
    cout << "v1 + v2: " << v1 + v2 << "\n";
    cout << "v3: " << v3 << "\n";
    cout << "v4: " << v4 << "\n";
    cout << "v3 % v4: " << v3 % v4 << "\n";
    cout << "v3 % v4: " << (v3 %= v4) << "\n";
}

void matr_test()
{
    double val = 1, a[3] = {1, 2, 3}, *p;
    // constructors
    matr_t<3, 3> m1(2), m2(1), m3;
    const matr_t<3, 3> cm(3);
    // math operators
    m1 += m2;
    m1 -= m2;
    m1 *= val;
    m1 /= val;
    // other operators
    m3 = m1;
    val = m1(1, 1);
    val = m1[1][1];
    val = cm(1, 1);
    val = cm[1][1];
    // setters/getters for rows and columns
    m1.set_row(2, val);
    m1.set_row(1, a);
    m1.get_row(0, a);
    p = m1.get_row(1);
    m2.set_col(2, val);
    m2.set_col(1, a);
    m2.get_col(0, a);
    // transpose matrix
    m1.transpose();       // self (only square matrix)
    cm.transposing(); // to other
    // elementary operations
    m1.row_mul(1, 2);  // multiply row by number
    m1.row_add_to(2, 1, -1);
    m1.row_swap(1, 2);         // swap two rows
    m2.col_mul(1, 2);  // multiply row by number
    m2.col_add_to(2, 1, -1);
    m2.col_swap(1, 2);         // swap two rows
    // math functions for square matrix
    val = m1.det();
    val = cm.trace();
    inv(m1);
    matr_t<5, 5> m5(1.2, 5.6, 7.4, 2.3, 1.5,
                    4.5, 5.1, 0.2, 8.8, 9.3,
                    7.7, 6.5, 4.6, 2.2, 6.3,
                    9.2, 4.5, 8.5, 0.7, 6.1,
                    3.2, 5.6, 4.7, 3.1, 1.4);
    time_t t = time(NULL);

    cout << m1 * m1 * m1 * m1 * m1 * m1 * m1 * m1;
    cout << pow(m1, 8);
}

void fixed_test()
{
    def::fixed_t<2> a(1), b(1.2), c(1.25), d(1.234), e(1.235);
    def::fixed_t<1> q(b), x(c);

    cout << a << "\n";
    cout << b << "\n";
    cout << c << "\n";
    cout << d << "\n";
    cout << e << "\n";
    cout << q << "\n";
    cout << x << "\n";
    cout << (a + b) << "\n";
    cout << (d + e) * b / c << "\n";
}

int main(void)
{
    fixed_test();

    return 0;
}
