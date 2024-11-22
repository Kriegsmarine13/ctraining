#include <stdio.h>
#include "include/logger.h"
#include "include/db.h"

int main(int argc, char **argv) {
    (void)argc;
    printf("Hello, World!\n");
    printf("Arg received: %s\n", argv[1]);
    switch (argv[1]) {
        case "log":
            logMessage(argv[2]);
            break;
        case "db":
            run(argv[2], argv[3], argv[4]);
            break;

    }
    // if (logMessage(argv[2])) {
    //     printf("Message logged\n");
    // } else {
    //     printf("Error logging message\n");
    // }
    return 0;
}