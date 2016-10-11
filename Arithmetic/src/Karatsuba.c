#include "Global.h"

/** \brief calculate size of a number of int
 *
 * \param x int
 * \return int
 *
 */
int size(int x)
{
    int count = 0;
    while (x > 0)
    {
        x /= 10;
        count++;
    }
    return count;
}

/** \brief get karatsuba x1
 *
 * \param x int
 * \param m double
 * \return int
 *
 */
int getHeight(int x, double m)
{
    return x/pow(10, m);
}

/** \brief get karatsuba x0
 *
 * \param x int
 * \param m double
 * \return int
 *
 */
int getLow(int x, double m)
{
    return x - getHeight(x, m)*pow(10, m);
}

/** \brief calcute the max number between x and y
 *
 * \param x int
 * \param y int
 * \return int
 *
 */
int max(int x, int y)
{
    return x>y?x:y;
}

/** \brief karatsuba multiplication 3*n^log3 3*n^1.585
 *
 * \param x int
 * \param y int
 * \return int
 *
 */
int Karatsuba(int x, int y)
{
    double m;
    int num;
    int x1, x0, y1, y0;
    int z2, z1, z0;

    if(x <= 10 || y <= 10)
    {
        return x*y;
    }
    num = max(size(x), size(y));
    m = (int)num/2;

    x1 = getHeight(x, m);
    x0 = getLow(x, m);
    y1 = getHeight(y, m);
    y0 = getLow(y, m);

    z2 = Karatsuba(x1, y1);
    z0 = Karatsuba(x0, y0);
    z1 = Karatsuba(x1+x0, y1+y0) - z0 - z2;
    printf("[x=%d][y=%d][m=%f]\n", x, y, m);
    printf("[x1=%d][x0=%d][y1=%d][y0=%d]\n", x1, x0, y1, y0);
    printf("[z2=%d][z1=%d][z0=%d]\n", z2, z1, z0);
    printf("[%f][%f][%f]\n", pow(10, 2*m), pow(10, m), m);
    printf("[result=%d]\n", (int)(z2*pow(10, 2*m) + z1*pow(10, m) + z0));
    return z2*pow(10, 2*m) + z1*pow(10, m) + z0;
}
