//
// Created by han1254 on 5/14/21.
//




#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char buf[80];
    getcwd(buf,sizeof(buf));
    printf("current working directory: %s\n", buf);
    int a[4][4];
    FILE* fpread;
    int temp;
    int type;
    int m, n;
    char* temps = (char*)malloc(sizeof(char));
    fpread = fopen("./_6_graph/data/data.txt", "r");
    if (fpread == NULL)
    {
        printf("file is error.");
        return -1;
    }
    fscanf(fpread, "%d\n", &type);
    printf("type:%d\n", type);
    fscanf(fpread, "%d %d\n", &m, &n);
    printf("m: %d, n: %d\n", m, n);
    int count = 0;
    while(count < m && fgets(temps, m, fpread) != NULL){
        printf("%s", temps);
        count++;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            fscanf(fpread, "%d", &temp);

            printf("%d\n", temp);
        }
    }
    fclose(fpread);

    return 0;
}
