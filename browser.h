#ifndef BROWSER_H
#define BROWSER_H
#include "adt_set.h"
#include "adt_map.h"

typedef struct {
    WebPageSet pages;
    CacheMap   cache;
    boolean    running;
} Browser;

void openPage(Browser *b, const char *url);
void cmdDiscover(Browser *b);
#endif
