#include <stdio.h>



int swap(int *val1, int *val2)
{
    int ret = 0;
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
    return ret;
}

/* 数组做函数会被弱化成指针,所以数组做参数必须要加一个数组大小 */
int printArray(int *array, int arraySize)
{
    for (int idx = 0 ; idx < arraySize; idx++)
    {
        printf("array[%d] = %d\n", idx, array[idx]);
    }
}

void bubbleSort(int *array, int arraySize)
{
    int sorted = 1;
    for (int end = arraySize; end > 0; end--)
        {
            /* 已经排序好 */
            sorted = 1;
            for (int begin = 1; begin < end; begin++)
            {
                /* 后面的数字比前面的数字小 就交换 */
                if (array[begin] < array[begin - 1])
                {
                    swap(&array[begin], &array[begin - 1]);
                    /* 在这里就说明一定还没有排好序 */
                    sorted = 0;
                }
            }
            if (sorted == 1)
            {
                break;
            }
        }
}

/* 优化3 */
void bubbleSort(int *array, int arraySize)
{
    int sortedIndx = 0;
    for (int end = arraySize; end > 0; end--)
        {
            /* 已经排序好 */
            sortedIndx = 1;
            for (int begin = 1; begin < end; begin++)
            {
                /* 后面的数字比前面的数字小 就交换 */
                if (array[begin] < array[begin - 1])
                {
                    swap(&array[begin], &array[begin - 1]);
                    /* 在这里就说明一定还没有排好序 */
                    sortedIndx = begin;
                }
            }
            /* 更新 */
            end = sortedIndx;
    
        }
}
int main()
{
    int array[] = {22, 34,12, 23, 56, 90, 4, 104, 35, 71};

    int len = sizeof(array) / sizeof(array[0]);
    bubbleSort(array, len);
    printArray(array, len);


    return 0;
}