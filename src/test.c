
// This file is a part of MRNIU/MiniCRT
// (https://github.com/MRNIU/MiniCRT).
//
// test.c for MRNIU/MiniCRT.

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(int argc, char *argv[]) {
    char   buf[128] = {0};
    FILE * fpw      = fopen("test.txt", "w");
    char **v        = malloc(argc * sizeof(char *));
    for (int i = 0; i < argc; i++) {
        v[i] = malloc(strlen(argv[i]) + 1);
        strcpy(v[i], argv[i]);
    }

    for (int i = 0; i < argc; i++) {
        fprintf(fpw, "%s\t", v[i]);
    }
    fclose(fpw);

    FILE *fpr = fopen("test.txt", "r");
    int   len = 128;
    fread(buf, len, 1, fpr);
    printf("%s\n", buf);
    fclose(fpr);
    return 0;
}
