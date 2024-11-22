#include <stdio.h>
#include <stdbool.h>
#include "../include/logger.h"

bool logMessage(char *message) {
    if (message == NULL || message[0] == '\0') {
        perror("Message is empty or null");
        return false;
    }

    // const char *filename = "../logfile.txt";
    FILE *file = fopen("./logfile.log", "a");
    if (file == NULL) {
        perror("Error opening file");
        return false;
    }

    if (fprintf(file,"%s\n", message) < 0) {
        perror("Error printing message");
        fclose(file);
        return false;
    }

    if (fflush(file) != 0) {
        perror("fflush");
        fclose(file);
        return false;
    }
    // const char *log_message = message;
    // fprintf(file, "%s\n", message);
    if (fclose(file) != 0) {
        perror("fclose");
        return false;
    }
    return true;
}