#include "Global.h"

/** \brief quick sort O(n)
 *
 * \param array int*
 * \param begin int
 * \param end int
 * \return void
 *
 */
void quick_sort(int *array, int begin, int end)
{
    if(begin >= end-1){
        return;
    }
    int n = partition(array, begin, end);
    quick_sort(array, begin, n);
    quick_sort(array, n+1, end);
}
