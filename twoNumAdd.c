#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define ARRAYSIZE 20    //生成多大的数组
#define RANGE 100    //生成随机数的大小

int main()
{
    srand(time(NULL));
    int randomArray[ARRAYSIZE];
    memset(randomArray, 0, sizeof(randomArray));
    int target;
    for (int idx = 0; idx < ARRAYSIZE; idx++)     //生成随机数组
    {
        int num = rand() % RANGE + 1;     //生成1-100的随机数
        randomArray[idx] = num;       //将生成的随机数放在数组里
        //printf("%d\t",randomArray[idx]);
    }
    printf("请输入一个两个数相加的和：");
    scanf("%d",&target);
    int sum = 0;  //和
    int firstNum,secondNum;;    //开始遍历的数字
    int idx,index;      //索引
    int flag = 0;
    for(idx = 0; idx < ARRAYSIZE - 1; idx++)
    {
        for (index = idx + 1; index < ARRAYSIZE; index++)
        {
            firstNum = randomArray[idx];
            secondNum = randomArray[index];
            sum = firstNum + secondNum;        //将两个数相加
            if (sum = target)
            {
                flag = 1;
                printf("随机数组中相加等于target的数的索引是:%d %d\n", idx, index);
            }
        }
    }
    if(flag = 0)
    {
        printf("没有找到相加等于target的这两个数\n");
    }

    return 0;
}