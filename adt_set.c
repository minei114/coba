#include "adt_set.h"
#include <string.h>

void setInit(WebPageSet *s) {
    s->size = 0;
    s->nextId = 1;
    for (int i = 0; i < MAX_WEB_PAGES; i++) s->pages[i].active = FALSE;
}

WebPage *setSearch(WebPageSet *s, const char *url) {
    for (int i = 0; i < MAX_WEB_PAGES; i++) {
        if (s->pages[i].active && strcmp(s->pages[i].url, url) == 0) {
            return &s->pages[i];
        }
    }
    return NULL;
}
