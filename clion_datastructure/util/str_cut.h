//
// Created by han1254 on 6/10/21.
//

#ifndef CLION_DATASTRUCTURE_STR_CUT_H
#define CLION_DATASTRUCTURE_STR_CUT_H

#include <memory.h>
#include <malloc.h>

int str_copy(const char* source, int n, char dest[]) {
    if (n > strlen(source)) return 0;
    for (int i = 0; i < n; ++i) {
        dest[i] = source[i];
    }
    return 1;
}

int str_copy_str(const char* source, int n, char* dest) {
    if (n > strlen(source)) return 0;
    dest = (char*)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; ++i) {
        dest[i] = source[i];
    }
    return 1;
}

#endif //CLION_DATASTRUCTURE_STR_CUT_H
