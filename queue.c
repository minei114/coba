#include "queue.h"
#include <string.h>
#include <stdio.h>

void createQueue(Queue *q) {
    q->head = -1; q->tail = -1; q->size = 0;
}

int calculateTicks(const char *url) {
    return (strlen(url) / 5) + 2;
}

int enqueue(Queue *q, const char *url) {
    if (q->size >= DOWNLOAD_MAX_AMOUNT) {
        printf("Download tidak diterima, antrian sudah penuh.\n");
        return 0;
    }
    q->tail = (q->tail + 1) % DOWNLOAD_MAX_AMOUNT;
    if (q->head == -1) q->head = 0;
    
    strcpy(q->data[q->tail].url, url);
    q->data[q->tail].ticksTotal = calculateTicks(url);
    q->data[q->tail].ticksLeft = q->data[q->tail].ticksTotal;
    q->size++;
    printf("Download %s (%d ticks)\n", url, q->data[q->tail].ticksTotal);
    return 1;
}

int tickQueue(Queue *q) {
    if (q->size == 0) {
        printf("Antrian download saat ini kosong.\n");
        return 0;
    }
    DownloadItem *curr = &q->data[q->head];
    curr->ticksLeft--;
    
    if (curr->ticksLeft <= 0) {
        printf("%s selesai terdownload!\n", curr->url);
        q->head = (q->head + 1) % DOWNLOAD_MAX_AMOUNT;
        q->size--;
        if (q->size == 0) q->head = -1, q->tail = -1;
    } else {
        printf("Downloading %s... (%d ticks tersisa)\n", curr->url, curr->ticksLeft);
    }
    return 1;
}
boolean isQueueEmpty(DownloadQueue *q) {
    return q->size == 0;
}
