#include "RateOfSimilar.h"

/** \brief  相似度算法主方法（递归）
 *
 * \param strA char*
 * \param pABegin int
 * \param pAEnd int
 * \param strB char*
 * \param pBBegin int
 * \param pBEnd int
 * \param temp int**
 * \return int
 *
 */
int RateOfSimilar(char *strA, int pABegin, int pAEnd, char *strB, int pBBegin, int pBEnd, int **temp)
{
    int a = 0;
    int b = 0;
    int c = 0;

    if(pABegin > pAEnd){
        if(pBBegin > pBEnd)
        {
            return 0;
        }
        else
        {
            return pBEnd-pBBegin+1;
        }
    }
    if(pBBegin > pBEnd)
    {
        if(pABegin > pAEnd)
        {
            return 0;
        }
        else
        {
            return pAEnd-pABegin+1;
        }
    }

    if(strA[pABegin] == strB[pBBegin])
    {
        if(temp[pABegin+1][pBBegin+1] != 0)
        {
            a = temp[pABegin+1][pBBegin+1];
        }
        else
        {
            a = RateOfSimilar(strA, pABegin+1, pAEnd, strB, pBBegin+1, pBEnd, temp);
            temp[pABegin+1][pBBegin+1] = a;
        }
        return a;
    }
    else
    {
        if(temp[pABegin+1][pBBegin+1] != 0)
        {
            a = temp[pABegin+1][pBBegin+1];
        }
        else
        {
            a = RateOfSimilar(strA, pABegin+1, pAEnd, strB, pBBegin+1, pBEnd, temp);
            temp[pABegin+1][pBBegin+1] = a;
        }

        if(temp[pABegin+1][pBBegin] != 0)
        {
            b = temp[pABegin+1][pBBegin];
        }
        else
        {
            b = RateOfSimilar(strA, pABegin+1, pAEnd, strB, pBBegin, pBEnd, temp);
            temp[pABegin+1][pBBegin] = b;
        }

        if(temp[pABegin][pBBegin+1] != 0)
        {
            c = temp[pABegin][pBBegin+1];
        }
        else
        {
            c = RateOfSimilar(strA, pABegin, pAEnd, strB, pBBegin+1, pBEnd, temp);
            temp[pABegin][pBBegin+1] = c;
        }
        return min(min(a, b), c)+1;
    }
}

/** \brief 相似度算法主方法（循环）
 *
 * \param strA char*
 * \param lenA int
 * \param strB char*
 * \param lenB int
 * \return int
 *
 */
int RateOfSimilar_c(char *strA, int lenA, char *strB, int lenB)
{
    int i;
    int m, n;
    int **temp = NULL;

    temp = (int**)malloc(sizeof(int)*(lenA+1));
    if(temp == NULL)
    {
        perror("malloc error!");
        return -1;
    }
    memset(temp, 0x00, sizeof(int)*(lenA+1));
    for(i = 0; i <= lenA; i++)
    {
        temp[i] = (int*)malloc(sizeof(int)*(lenB+1));
        if(temp[i] == NULL)
        {
            perror("for malloc error!");
            return -1;
        }
        memset(temp[i], 0x00, sizeof(int)*(lenB+1));
        temp[i][0] = i;
    }
    for(i = 0; i <= lenB; i++)
    {
        temp[0][i] = i;
    }
    for(m = 1; m <= lenA; m++)
    {
        for(n = 1; n <= lenB; n++)
        {
            if(strA[m-1] == strB[n-1])
            {
                temp[m][n] = temp[m-1][n-1];
            }
            else
            {
                temp[m][n] = min(min(temp[m-1][n-1], temp[m-1][n]), temp[m][n-1])+1;
            }
        }
    }
//    for(m = 0; m <= lenA; m++)
//    {
//        for(n = 0; n <= lenB; n++)
//        {
//            printf("%d ", temp[m][n]);
//        }
//        putchar('\n');
//    }
//    putchar('\n');
    for(i = 0; i < lenA; i++)
    {
        free(temp[i]);
    }
    free(temp);

    return temp[lenA][lenB];
}

/** \brief 计算最小值
 *
 * \param x int
 * \param y int
 * \return int
 *
 */
int min(int x, int y)
{
    return x<y?x:y;
}

/** \brief 相似度算法测试（递归）
 *
 * \return void
 *
 */
void RateOfSimilar_test()
{
    int i;
//    int m, n;
    int rate = 0;
    int len_a = 0;
    int len_b = 0;
    int **temp = NULL;
	char a[] = "efsdfdabcdefgaabcdefgaabcdefgaabcdefgasfabcdefgefsdfdabcdefgaabcdefgaabcdefgaabcdefgasfabcdefg";
    char b[] = "efsdfdabcdefgaabcdefgaaefsdfdabcdefgaabcdefgaabcdefgaabcdefgasfabcdabcdefggaabcdefgasfabcdefg";
    len_a = strlen(a);
    len_b = strlen(b);

    temp = (int**)malloc(sizeof(int)*(len_a+1));
    if(temp == NULL)
    {
        perror("malloc error!");
        exit(-1);
    }
    memset(temp, 0x00, sizeof(int)*(len_a+1));
    for (i = 0; i < len_a+1; i++)
    {
        temp[i] = (int*)malloc(sizeof(int)*(len_b+1));
        if(temp[i] == NULL)
        {
            perror("for malloc error!");
            exit(-1);
        }
        memset(temp[i], 0x00, sizeof(int)*(len_b+1));
    }
    rate = RateOfSimilar(a, 0, len_a-1, b, 0, len_b-1, temp);
//    for (m = 0; m <= len_a; m++)
//    {
//        for (n = 0; n <=len_b; n++)
//        {
//            printf("%d ", temp[m][n]);
//        }
//        putchar('\n');
//    }
//    putchar('\n');
    for(i = 0; i <= len_a; i++)
    {
        free(temp[i]);
    }
    free(temp);
    if(rate == -1)
    {
        printf("[%s][%d][E] [rate=-1]\n", __FILE__, __LINE__);
    }else{
        printf("[%s][%d][I] [rate=%d]\n", __FILE__, __LINE__, rate);
    }
}

/** \brief 相似度算法测试（循环）
 *
 * \return void
 *
 */
void RateOfSimilar_c_test()
{
    int rate = 0;
    int len_a = 0;
    int len_b = 0;
	char a[] = "efsdfdabcdefgaabcdefgaabcdefgaabcdefgasfabcdefgefsdfdabcdefgaabcdefgaabcdefgaabcdefgasfabcdefg";
    char b[] = "efsdfdabcdefgaabcdefgaaefsdfdabcdefgaabcdefgaabcdefgaabcdefgasfabcdabcdefggaabcdefgasfabcdefg";

    len_a = strlen(a);
    len_b = strlen(b);
    rate = RateOfSimilar_c(a, len_a, b, len_b);
    if(rate == -1)
    {
        printf("[%s][%d][E] [rate=-1]\n", __FILE__, __LINE__);
    }else{
        printf("[%s][%d][I] [rate=%d]\n", __FILE__, __LINE__, rate);
    }
}
