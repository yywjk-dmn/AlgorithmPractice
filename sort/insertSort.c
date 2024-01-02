#include <stdio.h>

int printArray(int *array, int arraySize)
{
    for (int idx = 0 ; idx < arraySize; idx++)
    {
        printf("array[%d] = %d\n", idx, array[idx]);
    }
}

int insertSort(int *array, int arraySize)
{
    int ret = 0;
    for (int idx = 0; idx < arraySize; idx++)
    {
        int begin = idx;
        int insertValue = array[begin + 1];
        while (begin >= 0)
        {
            /* 如果当前位置的数要比要插入的数字大 那就将当前位置的数字后移一个 */
            if (array[begin] > insertValue)
            {
                array[begin + 1] = array[begin];
                begin--;
                //array[begin + 1] = insertValue;
            }
            else
            {
                break;
            }
            array[begin] = insertValue;
        }

    }
    return ret;

}

int insertSort02(int *array, int arraySize)
{
    int ret = 0;
    int copyNum = 0;
    int cur = 0;
    for (int idx = 1; idx < arraySize; idx++)
    {
        copyNum = array[idx];
        while (copyNum < array[cur - 1])
        {
            array[cur] = array[cur - 1];
            cur--;
        }
        array[cur] = copyNum;
    }
    return ret;

}

 int main()
 {
    int array[] = {22, 34, 12, 23, 56, 90, 4, 104, 35, 71};
    int len = sizeof(array) / sizeof(array[0]);

    insertSort(array, len);
    printArray(array, len);



    return 0;
 }