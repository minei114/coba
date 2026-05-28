#ifndef QUEUE_H
#define QUEUE_H
#include "types.h"

typedef struct {
    char url[MAX_URL_LEN];
    int ticksTotal;
    int ticksLeft;
} DownloadItem;

typedef struct {
    DownloadItem data[DOWNLOAD_MAX_AMOUNT];
    int head;
    int tail;
    int size;
} Queue;

void createQueue(Queue *q);
int enqueue(Queue *q, const char *url);
boolean isQueueEmpty(Queue *q);
void printQueue(Queue *q);
int tickQueue(Queue *q); /* Memproses waktu download [10] */
#endif
