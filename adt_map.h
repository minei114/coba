#ifndef ADT_MAP_H
#define ADT_MAP_H
#include "types.h"

typedef struct {
    char    key[MAX_URL_LEN];
    char    value[MAX_CONTENT_LEN];
    int     order; 
    boolean used;
} MapEntry;

typedef struct {
    MapEntry entries[CACHE_MAX_AMOUNT];
    int      size;
    int      counter;
} CacheMap;

void mapInit(CacheMap *m);
void mapRemove(CacheMap *m, const char *url);
void mapPut(CacheMap *m, const char *key, const char *value);
char *mapGet(CacheMap *m, const char *key);
#endif
