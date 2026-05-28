#include "browser.h"
#include "graph.h"
#include "queue.h"
#include "adt_array.h"

int main() {
    WebPageSet database;
    CacheMap cache;
    Graph webGraph;
    TabArray tabs;
    Queue downloadQueue;

    // Inisialisasi semua ADT
    setInit(&database);
    mapInit(&cache, CACHE_MAX_AMOUNT);
    graphInit(&webGraph);
    tabArrayInit(&tabs);
    createQueue(&downloadQueue);

    char input[MAX_STR_LEN];
    while (TRUE) {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        // Parsing command: OPEN_PAGE, NEWTAB, DISCOVER, dll.
        // Jika EXIT (Spek STI S03): [8, 16]
        if (strcmp(input, "EXIT") == 0) {
            printf("B R O W S E R\nMematikan ShackBrowser...\n");
            break;
        }
    }
    return 0;
}
