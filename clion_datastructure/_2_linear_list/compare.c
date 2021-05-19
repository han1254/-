//
// Created by han1254 on 5/18/21.
//

#include <stdio.h>
#include "string.h"
int compare(char* a, char* b) {
    int i = 0;
    int l1 = strlen(a);
    int l2 = strlen(b);
    int len = l1 < l2 ? l1 : l2;
    while (i < len && a[i] == b[i]) i++;
    if (i < len) {
        return a[i] > b[i] ? 1 : -1;
    } else {
        if (l1 == l2) return 0;
        else return l1 < l2 ? -1 : 1;
    }

}




int main() {
    char* t1 = "cccc";
    char* t2 = "abab";

}
