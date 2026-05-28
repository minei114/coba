#include "browser.h"
#include "utils.h"
#include <stdio.h>

void openPage(Browser *b, const char *url) {
    char *cached = mapGet(&b->cache, url);
    if (cached) {
        printf("[Status: Cache-Hit] Mengambil data dari cache...\n\n%s\n", cached); // [10]
        return;
    }
    WebPage *p = setSearch(&b->pages, url);
    if (p) {
        printf("[Status: Cache-Miss] Mengambil data dari database...\n\n%s\n", p->content); // [11]
        mapPut(&b->cache, url, p->content);
    } else {
        printf("404 Not Found! Halaman tidak ditemukan.\n");
    }
}

void cmdDiscover(Browser *b) {
    int activeIdx[MAX_WEB_PAGES], total = 0;
    for (int i = 0; i < MAX_WEB_PAGES; i++) {
        if (b->pages.pages[i].active) activeIdx[total++] = i;
    }
    if (total == 0) return;
    int show = (total < 5) ? total : 5;
    printf("Berikut adalah beberapa halaman yang mungkin menarik untukmu:\n");
    for (int i = 0; i < show; i++) {
        int r = lcgRand(total); // [1, 12]
        printf("- %s\n", b->pages.pages[activeIdx[r]].url);
    }
}
