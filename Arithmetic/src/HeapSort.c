#include "Global.h"

/** \brief 大根堆排序调整节点与子节点位置 O(nlgn)
 *
 * \param array[] int
 * \param i int
 * \param length int
 * \return void
 *
 */
void BigRootHeapAdjust(int array[],int i, int length)
{
    int nChild = 2*i+1;
    for (;2*i+1 < length ;i = nChild )
    {
        /**< 左子节点 */
        nChild = 2*i+1;
        /**< 找到子节点中的最大值 */
        if (nChild<length-1&&array[nChild+1]>array[nChild])
        {
            nChild++;
        }
        /**< 节点值与子节点中的最大值进行判断和调整 */
        if (array[i] < array[nChild])
        {
            /**< 当前节点小于子节点 */
            array[i] = array[i] ^ array[nChild];
            array[nChild] = array[i] ^ array[nChild];
            array[i] = array[i] ^ array[nChild];
        }
        else
        {
            /**< 当前节点大于子节点 */
            break;
        }
    }
}

/** \brief 大根堆排序算法（升序算法）
 *
 * \param array[] int
 * \param length int
 * \return void
 *
 */
void BigRootHeapSort(int array[], int length)
{
    int i;
    /**< 找到最后一个非叶子节点 */
    /**< length/2-1为满二叉树最后一个非叶子节点 */
    for(i = length/2-1; i >=0; i--)
    {
        /**< 调整数据位置 */
        BigRootHeapAdjust(array, i, length);
    }

    /**< 循环调整父节点与叶子节点的位置使其符合堆排序特点（父节点比子节点大） */
    for(i = length-1; i > 0; i--)
    {
        /**< 调整后的第一个数据为未排序数据中的最大值 */
        array[0] = array[0] ^ array[i];
        array[i] = array[0] ^ array[i];
        array[0] = array[0] ^ array[i];
        /**< 将最大值与数组尾值进行交换，并再次调整数组，直到所有数据排序完成 */
        BigRootHeapAdjust(array, 0, i);
    }
}
