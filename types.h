#ifndef TYPES_H
#define TYPES_H

#define MAX_URL_LEN         256
#define MAX_CONTENT_LEN     4096
#define MAX_WEB_PAGES       200
#define CACHE_MAX_AMOUNT    10
#define TRUE  1
#define FALSE 0

typedef int boolean;

typedef struct {
    int     id;
    char    url[MAX_URL_LEN];
    char    content[MAX_CONTENT_LEN];
    int     view_count;
    boolean active;
} WebPage;

#endif
