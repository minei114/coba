#ifndef BROWSER_H
#define BROWSER_H

#include "types.h"
#include "adt_set.h"
#include "adt_map.h"
#include "graph.h"
#include "queue.h"
#include "adt_array.h"

typedef struct {
    WebPageSet pages;
    CacheMap cache;

    Graph graph;
    Queue downloadQueue;
    TabArray tabs;

    boolean running;
} Browser;

void openPage(Browser *b, const char *url);
void cmdDiscover(Browser *b);

#endif
