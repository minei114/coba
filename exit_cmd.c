#include "exit_cmd.h"
#include <stdio.h>

#define COLOR_RED "\033[1;31m"
#define COLOR_RESET "\033[0m"

void cmdExit(Browser *b) {
    printf(COLOR_RED "\n=================================\n");
    printf("          S H A C K           \n");
    printf("        B R O W S E R         \n");
    printf("=================================\n" COLOR_RESET);
    printf("Mematikan ShackBrowser...\n");
    b->running = FALSE;
}
