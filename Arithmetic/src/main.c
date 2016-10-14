#include "Global.h"
#include "RateOfSimilar.h"

void quick_test();
void part_test();
void appnum_test();
void count1_test();
void karatsuba_test();
void regular_multi_test();
void heap_sort_test();

int main()
{
    RateOfSimilar_test();
    RateOfSimilar_c_test();
//    printf("%d\n", (int)pow(10, 2*1));
//    quick_test();
//    part_test();
//    appnum_test();
//    count1_test();
//    karatsuba_test();
//    regular_multi_test();
//    heap_sort_test();
    return 0;
}

void heap_sort_test()
{
    int i;
    int num[]={2,4,0,6,5,8,3,1,9,7,4,0,6,5,8,3,1,9,7,4,0,6,5,8,3,1,9,7,4,0,6,5,8,3,1,9,7};
    BigRootHeapSort(num,sizeof(num)/sizeof(int));
    for(i=0;i<sizeof(num)/sizeof(int);i++)
    {
        printf("%d ",num[i]);
    }
    printf("\nok\n");
}

void regular_multi_test()
{
    int x = 11111;
    int y = 22222;
    int mul = 0;
    mul = x*y;
    printf("[%s][%d][I] [mul=%d]\n", __FILE__, __LINE__, mul);
}

void karatsuba_test()
{
    int x = 11111;
    int y = 22222;
    int mul = 0;
    mul = Karatsuba(x, y);
    printf("[%s][%d][I] [mul=%d]\n", __FILE__, __LINE__, mul);
}

void count1_test()
{
    int m = 1023;
    int num = 0;
    int i;
    int n = 1;
    n = n<<30;
    printf("[%s][%d][I] [n=%d]\n", __FILE__, __LINE__, n);
    printf("[%s][%d][I] ", __FILE__, __LINE__);
    for (i = 0; i < sizeof(int)*8-1; i++)
    {
        if(n&m)
            putchar('1');
        else
            putchar('0');
        n = n>>1;
    }
    putchar('\n');
    num = getCountOf1(m);
    printf("[%s][%d][I] [num=%d]\n", __FILE__, __LINE__, num);
}

void appnum_test()
{
    int m = 1000, n = 1001;
    int app = -1;
    printf("[%s][%d][I] appnum_test\n", __FILE__, __LINE__);
    app = getMaxAppNumber(m, n);
    printf("app:%d\n", app);
}

void quick_test()
{
    int i = 0;
    int array[] = {18, 18, 4, 5, 22, 23, 9, 23, 12, 50, 33, 342, 234, 11, 2334, 34, 32, 21, 1};
    printf("arithmetic example!\n");
    printf("quick sort:\n");
    printf("%d\n", sizeof(array)/sizeof(int));
    quick_sort(array, 0, sizeof(array)/sizeof(int));
    for(i = 0; i < sizeof(array)/sizeof(int); i++)
    {
        printf("%d ", array[i]);
    }
    putchar('\n');
}
void part_test()
{
    int i = 0;
    int array[] = {1,2,3,3,2,1,2,3,2,1,2,3,3,2,1,2,3,2,1,2,3,2,3,2,3,2,1,2,3,2,1,2};
    printf("arithmetic example!\n");
    printf("quick sort:\n");
    printf("%d\n", sizeof(array)/sizeof(int));
    part_by_target(array, 0, sizeof(array)/sizeof(int), 2);
    for(i = 0; i < sizeof(array)/sizeof(int); i++)
    {
        printf("%d ", array[i]);
    }
    putchar('\n');
}


