//
// Created by han1254 on 4/24/21.
//

#include <string.h>
#include "stdio.h"
#include "stdlib.h"
int main() {
//    char read[10];
//    scanf("%s", read);
//    getchar();
//    int i = 0;
//    while(read[i] != '\0') {
//        printf("%c", read[i++]);
//    }

//    printf("\n");
    char *sp;
    sp=(char *)malloc(sizeof(char));
    scanf("%s",sp);
    printf("%s,%c\n",sp,*sp);//pointer,p
    printf("%lu\n", strlen(sp));
    return 0;
}