#include "Global.h"

/** \brief �������������ڵ����ӽڵ�λ�� O(nlgn)
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
        /**< ���ӽڵ� */
        nChild = 2*i+1;
        /**< �ҵ��ӽڵ��е����ֵ */
        if (nChild<length-1&&array[nChild+1]>array[nChild])
        {
            nChild++;
        }
        /**< �ڵ�ֵ���ӽڵ��е����ֵ�����жϺ͵��� */
        if (array[i] < array[nChild])
        {
            /**< ��ǰ�ڵ�С���ӽڵ� */
            array[i] = array[i] ^ array[nChild];
            array[nChild] = array[i] ^ array[nChild];
            array[i] = array[i] ^ array[nChild];
        }
        else
        {
            /**< ��ǰ�ڵ�����ӽڵ� */
            break;
        }
    }
}

/** \brief ����������㷨�������㷨��
 *
 * \param array[] int
 * \param length int
 * \return void
 *
 */
void BigRootHeapSort(int array[], int length)
{
    int i;
    /**< �ҵ����һ����Ҷ�ӽڵ� */
    /**< length/2-1Ϊ�����������һ����Ҷ�ӽڵ� */
    for(i = length/2-1; i >=0; i--)
    {
        /**< ��������λ�� */
        BigRootHeapAdjust(array, i, length);
    }

    /**< ѭ���������ڵ���Ҷ�ӽڵ��λ��ʹ����϶������ص㣨���ڵ���ӽڵ�� */
    for(i = length-1; i > 0; i--)
    {
        /**< ������ĵ�һ������Ϊδ���������е����ֵ */
        array[0] = array[0] ^ array[i];
        array[i] = array[0] ^ array[i];
        array[0] = array[0] ^ array[i];
        /**< �����ֵ������βֵ���н��������ٴε������飬ֱ����������������� */
        BigRootHeapAdjust(array, 0, i);
    }
}
