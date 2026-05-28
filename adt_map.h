typedef struct {
    char key[MAX_URL_LEN];
    char value[MAX_CONTENT_LEN];
    int order; // LRU Order
    boolean used;
} MapEntry;

typedef struct {
    MapEntry entries[CACHE_MAX_AMOUNT];
    int counter; // Untuk increment order
} CacheMap;
