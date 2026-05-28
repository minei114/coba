#ifndef ADT_SET_H
#define ADT_SET_H
#include "types.h"

typedef struct {
    WebPage pages[MAX_WEB_PAGES];
    int     size;
    int     nextId;
} WebPageSet;

boolean setInsert(WebPageSet *s, const char *url, const char *content);
void setDelete(WebPageSet *s, const char *url);
void setInit(WebPageSet *s);
WebPage *setSearch(WebPageSet *s, const char *url);
#endif
