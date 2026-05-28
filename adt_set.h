#ifndef ADT_SET_H
#define ADT_SET_H
#include "types.h"

typedef struct {
    WebPage pages[MAX_WEB_PAGES];
    int     size;
    int     nextId;
} WebPageSet;

void setInit(WebPageSet *s);
WebPage *setSearch(WebPageSet *s, const char *url);
#endif
