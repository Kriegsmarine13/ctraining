#include <stdio.h>
#include "../include/db.h"
#include <string.h>

#define BUF_SIZE 65536

char run(char *cmd, char *target, char *values) {
    char *mode = "r";
    switch (cmd) {
        case "set":
            mode = "a+";
            break;
        case "get":
            mode = "r";
            break;
        case "del":
            mode = "w";
            break;
        default:
            mode = "r";
            break;
    }

    FILE *file = fopen("./tmp.db", mode);
    if (file == NULL) {
        printf("Error accessing DB file\n");
    }

    if (cmd == "set") {

    }
}

int countLines(FILE* file) {
    char buf[BUF_SIZE];
    int counter = 0;
    for (;;) {
        size_t res = fread(buf, 1, BUF_SIZE, file);
        if (ferror(file))
            return -1;

        // int i;
        for (int i = 0; i < res; i++) {
            if (buf[i] == '\n')
                counter++;
        }

        if (feof(file))
            break;
    }

    return counter;
}