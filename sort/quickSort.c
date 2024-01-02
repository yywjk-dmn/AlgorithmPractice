#include <stdio.h>



int printArray(int *array, int arraySize)
{
    for (int idx = 0 ; idx < arraySize; idx++)
    {
        printf("array[%d] = %d\n", idx, array[idx]);
    }
}

int quickSort(int *array, int start, int end, int arraySize)
{
    /* 递归必须考虑函数结束条件 */
    int ret = 0;
    int baseNum = 0;
    int idx = start; 
    int jdx = end;
    while (start != end)
    {
        #if 0
        for (start = 0; start < arraySize; start++)
        {
            baseNum = array[start];
            for (end = arraySize; end > 0; end--)
            {
                if (array[end] < baseNum)
                {
                    array[end] = array[start];
                }
                else
                {
                    return baseNum;
                    break;
                }
            }
            if (array[start] > baseNum)
            {
                array[end] = array[start];
            }
            else
            {
                return baseNum;
                break;
            }
        }
        #endif
        baseNum = array[start];
        if (array[start] > baseNum)
        {
            array[end] = array[start];
            start++;
        }
        else 
        {
            start++;
        }

    }
    quickSort(array, idx, start - 1, arraySize);
    quickSort(array, start + 1, jdx, arraySize);
    
   




    return ret;

}
static findBaseValPos(int *array, int start, int end)
{
    int ret = 0;
    /* 怕越界 所以需要-- */
    end--;

    /* 基准值 */
    int baseValPos = array[start];
    while (start < end)
    {
        while (start < end)
        {
            if (array[end] < baseValPos)
            {
                array[start++] = array[end];
                break;
            }
            else
            {
                end--;
            }
        }

        while (start < end)
        {
            if (array[start] > baseValPos)
            {
                array[end--] = array[start];
            }
            else 
            {
                start++;
            }
            
        }
    }
    /* 这行是什么意思  有点不明白 */
    array[start] = baseValPos;
    return start;


}
int quickSort01(int *array, int start, int end)
{
    int ret = 0;
    if (array == NULL)
    {
        return ret;
    }
    
    if (start >= end)
    {
        return ret;
    }
    int baseValPos = findBaseValPos(array, start, end);

    /* 对基准值左边排序 */
    quickSort01(array, start, baseValPos);
    /* 对基准值右边排序 */
    quickSort01(array, baseValPos + 1, end);

    return ret;

}


int main()
{
    int array[] = {22, 34, 12, 23, 56, 90, 4, 104, 35, 71};
    int len = sizeof(array) / sizeof(array[0]);

    quickSort(array, 0, len - 1, len);
    printArray(array, len);


    return 0;
}