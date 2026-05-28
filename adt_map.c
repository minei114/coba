#include "adt_map.h"
#include <string.h>

void mapInit(CacheMap *m) {
    m->size = 0;
    m->counter = 0;
    for (int i = 0; i < CACHE_MAX_AMOUNT; i++) m->entries[i].used = FALSE;
}

char *mapGet(CacheMap *m, const char *key) {
    for (int i = 0; i < CACHE_MAX_AMOUNT; i++) {
        if (m->entries[i].used && strcmp(m->entries[i].key, key) == 0) {
            m->entries[i].order = ++m->counter; // Update LRU order [9]
            return m->entries[i].value;
        }
    }
    return NULL;
}

void mapPut(CacheMap *m, const char *key, const char *value) {
    int idx = -1, minOrder = m->counter + 1;
    if (m->size >= CACHE_MAX_AMOUNT) { // LRU Victim Search [6]
        for (int i = 0; i < CACHE_MAX_AMOUNT; i++) {
            if (m->entries[i].order < minOrder) {
                minOrder = m->entries[i].order;
                idx = i;
            }
        }
    } else {
        for (int i = 0; i < CACHE_MAX_AMOUNT; i++) {
            if (!m->entries[i].used) { idx = i; break; }
        }
        m->size++;
    }
    m->entries[idx].used = TRUE;
    m->entries[idx].order = ++m->counter;
    strncpy(m->entries[idx].key, key, MAX_URL_LEN);
    strncpy(m->entries[idx].value, value, MAX_CONTENT_LEN);
}
