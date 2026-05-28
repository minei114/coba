#include "adt_set.h"
#include <string.h>

void setInit(WebPageSet *s) {

    s->size = 0;
    s->nextId = 1;

    for (int i = 0; i < MAX_WEB_PAGES; i++) {
        s->pages[i].active = FALSE;
    }
}

WebPage *setSearch(WebPageSet *s, const char *url) {

    for (int i = 0; i < MAX_WEB_PAGES; i++) {

        if (s->pages[i].active &&
            strcmp(s->pages[i].url, url) == 0) {

            return &s->pages[i];
        }
    }

    return NULL;
}

boolean setInsert(WebPageSet *s,
                  const char *url,
                  const char *content) {

    for (int i = 0; i < MAX_WEB_PAGES; i++) {

        if (!s->pages[i].active) {

            s->pages[i].id = s->nextId++;

            strcpy(s->pages[i].url, url);
            strcpy(s->pages[i].content, content);

            s->pages[i].view_count = 0;
            s->pages[i].active = TRUE;

            s->size++;

            return TRUE;
        }
    }

    return FALSE;
}

void setDelete(WebPageSet *s, const char *url) {

    for (int i = 0; i < MAX_WEB_PAGES; i++) {

        if (s->pages[i].active &&
            strcmp(s->pages[i].url, url) == 0) {

            s->pages[i].active = FALSE;

            s->size--;

            return;
        }
    }
}
