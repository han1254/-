#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int judge(char* A, int n)
{
    int i = 0;
    int j = 0, k = 0;
    while(A[i] != '\0')
    {
        switch(A[i])
        {
            case 'I': j++; break;
            case 'O': k++;
                if(k > j)
                {
                    printf("序列非法!\n");
                    exit(0);
                }

        }
        i++;
    }
    if(j != k)
    {
        printf("序列非法！\n");
        return 0;
    }
    printf("合法!\n");
    return 0;
}

int main()
{
    int n;
    printf("enter the number of characters which you want to check:\n");
    scanf("%d",&n);
    getchar();
    char t[n+1];
    printf("enter the string:\n");
    fgets(t, n+1, stdin);
    judge(t, n);
}
