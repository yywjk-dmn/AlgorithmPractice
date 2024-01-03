#include <stdio.h>
#include <string.h>

#if 1
#define BUFFER_SIZE 6

int stringIsValid(char *array)
{
    int ret = 0;
    int len = strlen(array);

    /* count ++ 将有用的计数 用来进行括号的匹配 */
    int count = 0;
    int startASCII = 0;
    int endASCII = 0;
    for (int idx = 0; idx < len; idx++)
    {
        int firstPtr = array[idx];
        int endPtr = array[len - 1];
        
        /* 开头和结尾的ASCII值 */
        startASCII = (int)array[idx];
        endASCII = (int)array[len - 1];

        while (firstPtr > endPtr)
        {
            if (startASCII + 2 == endASCII || startASCII + 1 == endASCII)
            {
                /* 说明找到了配套的括号 */
                ret = 1;
                return ret;
            }
        }

        return ret;

    }


}

int main()
{
    int ret = 0;
    
    char array[BUFFER_SIZE] = "(([]))";
    if (array == NULL)
    {
        return ret;
    }
    ret = stringIsValid(array);
    printf("ret:%d\n", ret);
  

    return ret;
}

#else
char string(char a)
{
    if (a == '(')
    {
        return ')';
    }
    if (a == '[')
    {
        return ']';
    }
    if (a == '{')
    {
        return '}';
    }
}

int stringIsVaild(char *s)
{
    int len = strlen(s);
    if (len % 2 == 1)
    {
        return 0;
    }
    int stk[len + 1];
    int top = 0;
    for (int idx = 0; idx < len; idx++)
    {
        char ch1 = string(s[idx]);
        if (ch1)
        {
            if (top == 0 || stk[top - 1] != ch1)
            {
                return 0;
            }
            top--;

        }
        else
        {
            stk[top++] = s[idx];
        }
    }
    return top == 0;

}
#endif