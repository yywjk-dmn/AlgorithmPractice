#include <stdio.h>

#define BUFF_SIZE 7

#if 0
/* 自己写的代码 */
int main()
{
    int array[BUFF_SIZE] = {1, 30, 24, 5, 58, 12, 39};
    int swappos = 0;
    //memset(array, 0, sizeof(array));
    for (int idx = 0; idx < BUFF_SIZE; idx++)
    {
        int minNum = array[idx];
        for (int jdx = idx + 1; jdx < BUFF_SIZE; jdx++)
        {
            
            if (array[jdx] < minNum)
            {
                minNum = array[jdx];
                /* 记录最小值的位置 */
                swappos = jdx;
            }
        }
        int temp = array[swappos];
        array[swappos] = array[idx];
        array[idx] = temp;

        printf("%d\t", array[idx]);


    }
    



    
    return 0;
}
#endif


int printArray(int *array, int arraySize)
{
    for (int idx = 0 ; idx < arraySize; idx++)
    {
        printf("array[%d] = %d\n", idx, array[idx]);
    }
}

int selectSort(int *array, int arraySize)
{
    
    int ret = 0;
    int minValue = 0;
    int minIndex = 0;
    for (int pos = 0; pos < arraySize; pos ++)
    {
        int min = array[pos];
        for (int begin = pos + 1; begin < arraySize; begin++)
        {
            /* 遍历的元素要是比最小值还小的话 就将最小值进行更新 */
            if (min > array[begin])
            {
                minValue = array[begin];
                minIndex = begin;
            }

        }

        if (array[pos] > min)
        {
            int temp = array[pos];
            array[pos] = min;
            array[minIndex] = temp;

        }
    }
  


}
int main()
{
    int array[] = {22, 34, 12, 23, 56, 90, 4, 104, 35, 71};
    int len = sizeof(array) / sizeof(array[0]);

    selectSort(array, len);
    printArray(array, len);

    return 0;
}