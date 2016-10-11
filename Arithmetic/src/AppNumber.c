#include "Global.h"

int getMaxAppNumber(int num1, int num2)
{
    int bignum, smallnum;
    if(num1 <= 0 || num2 <= 0)
    {
        printf("[%s][%d][E] parameter error[%d][%d]\n", __FILE__, __LINE__, num1, num2);
        return -1;
    }
    if(num1 >= num2){
        bignum = num1;
        smallnum = num2;
    }else{
        bignum = num2;
        smallnum = num1;
    }
    if(bignum%smallnum == 0){
        return smallnum;
    }else{
        bignum = bignum%smallnum;
        return getMaxAppNumber(bignum, smallnum);
    }
}
