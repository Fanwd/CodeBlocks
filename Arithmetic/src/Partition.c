#include "Global.h"

int partition(int *arr, int begin, int end)
{
    int ptnum = arr[begin];
    while(begin < end)
    {
        while(begin < end && arr[--end] >= ptnum);
        arr[begin] = arr[end];
        while(begin < end && arr[++begin] <= ptnum);
        arr[end] = arr[begin];
    }
    arr[begin] = ptnum;
    return begin;
}
void part_by_target(int *array, int begin, int end, int target)
{
    int next_small = begin;
    int next_big = end - 1;
    int next_scan = begin;
    putchar('\n');
    while(next_scan < next_big)
    {
        if(array[next_scan] < target)
        {
            swap_int(&array[next_scan++], &array[next_small++]);
        }
        else if(array[next_scan] > target)
        {
            swap_int(&array[next_scan], &array[next_big--]);
        }else
        {
            next_scan++;
        }
    }
}
