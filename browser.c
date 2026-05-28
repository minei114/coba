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
