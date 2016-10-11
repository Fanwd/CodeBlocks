#include "Global.h"

/** \brief find the count of 1 in the number 'm'
 *
 * \param m int
 * \return int
 *
 */
int getCountOf1(int m)
{
    int count = 0;
    while(m > 0){
        m &= m - 1;
        count++;
    }
    return count;
}
