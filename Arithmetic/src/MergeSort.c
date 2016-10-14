#include "MergeSort.h"

/** \brief 归并排序主方法
 *
 * \param array int*
 * \param seqn int
 * \param size int
 * \param sortArray int*
 * \return void
 *
 */
void MergeSort(int *array,int begin, int end, int *sortArray)
{
    if(begin < end)
    {
        MergeSort(array, begin, (begin+end)/2, sortArray);
        MergeSort(array, (begin+end)/2+1, end, sortArray);
        MergeArray(array, begin, end, (begin+end)/2, sortArray);
    }
}

/** \brief 合并数组
 *
 * \param array int*
 * \param start int
 * \param end int
 * \param middle int
 * \param temp int*
 * \return void
 *
 */
void MergeArray(int *array, int start, int end, int middle, int *temp)
{
    int i = start;
    int m = start;
    int n = middle+1;
    while(m <= middle && n <= end)
    {
        if(array[m] <= array[n])
        {
            temp[i++] = array[m++];
        }
        else
        {
            temp[i++] = array[n++];
        }
    }
    while(m <= middle)
    {
        temp[i++] = array[m++];
    }
    while(n <= end)
    {
        temp[i++] = array[n++];
    }
    for(i = start; i <= end; i++)
    {
        array[i] = temp[i];
    }
}

/** \brief 归并排序测试
 *
 * \return void
 *
 */
void MergeSort_test()
{
    int i;
    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 93, 88, 43, 2, 80, 96, 21, 31, 71, 84, 48,
    18, 5, 22, 57, 66, 83, 34, 53, 11, 29, 52, 64, 32, 10, 3, 76, 24, 8, 13, 9, 94, 1,
    39, 60, 100, 54, 25, 37, 86, 78, 97, 62, 15, 73, 98, 91, 14, 36, 69};
    int *b = NULL;
    b = (int*)malloc(sizeof(a));
    if(b == NULL)
    {
        perror("malloc error!");
        exit(-1);
    }
    MergeSort(a, 0, sizeof(a)/sizeof(int)-1, b);
    for(i = 0; i < sizeof(a)/sizeof(int); i++)
    {
        printf("%d ", a[i]);
    }
    putchar('\n');
}
