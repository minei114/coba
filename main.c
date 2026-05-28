#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "browser.h"
#include "exit_cmd.h"
#include "f10.h"
#include "history_view.h"
#include "cmd_pages.h"
#include "utils.h"

int main() {
    Browser b;
    // Inisialisasi semua ADT dari sumber
    setInit(&b.pages);            // [13]
    mapInit(&b.cache);        // [14]
    graphInit(&b.graph);          // [15]
    tabArrayInit(&b.tabs);        // [16]
    createQueue(&b.downloadQueue);// [17]
    b.running = TRUE;

    char input[MAX_STR_LEN];
    char cmd[18], arg[MAX_URL_LEN];

    printf("\nSelamat datang di Shack Browser!\n");

    while (b.running) {
        printf("\n[%s] > ", tabGetCurrent(&b.tabs)->name); // [19]
        if (fgets(input, sizeof(input), stdin) == NULL) break;
        
        arg[0] = '\0';
        if (sscanf(input, "%s %[^\n]", cmd, arg) < 1) continue;

        if (strcmp(cmd, "DISCOVER") == 0) {
            cmdDiscover(&b); // [20]
        } else if (strcmp(cmd, "OPEN_PAGE") == 0) {
            openPage(&b, arg); // [21]
            tabPushHistory(&b.tabs, arg); // [19]
        } else if (strcmp(cmd, "SEARCH") == 0) {
            /* Implementasi Search F02 [22] */
            for (int i = 0; i < MAX_WEB_PAGES; i++) {
                if (b.pages.pages[i].active && startsWith(b.pages.pages[i].url, arg)) {
                    printf("- %s\n", b.pages.pages[i].url);
                }
            }
        } else if (strcmp(cmd, "ADD_PAGE") == 0) {
            cmdAddPage(&b, arg); // [23]
        } else if (strcmp(cmd, "DELETE_PAGE") == 0) {
            cmdDeletePage(&b, arg); // [24]
        } else if (strcmp(cmd, "TABS") == 0) {
            tabPrint(&b.tabs); // [25]
        } else if (strcmp(cmd, "NEWTAB") == 0) {
            tabAdd(&b.tabs); // [26]
        } else if (strcmp(cmd, "NEXTTAB") == 0) {
            if (isPositiveInt(arg)) tabMove(&b.tabs, 1, atoi(arg)); // [27]
        } else if (strcmp(cmd, "BACK") == 0) {
            char outUrl[MAX_URL_LEN];
            jumpBack(&tabGetCurrent(&b.tabs)->nav, 1, outUrl); // [28]
            openPage(&b, outUrl);
        } else if (strcmp(cmd, "HISTORY") == 0) {
            displayTabHistory(tabGetCurrent(&b.tabs)->nav); // [28]
        } else if (strcmp(cmd, "DOWNLOAD") == 0) {
            cmdDownload(&b, arg);
        } else if (strcmp(cmd, "TICK") == 0) {
            cmdTick(&b);
        } else if (strcmp(cmd, "EXIT") == 0) {
            cmdExit(&b); // [29] S03 STI: Pesan sebelum keluar
        } else {
            printf("Perintah tidak dikenali.\n");
        }
    }
    return 0;
}
