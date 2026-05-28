#include "f10.h"
#include "queue.h"
#include <stdio.h>
#include <string.h>
#include "queue.h"

void cmdDownload(Browser *b, const char *url) {
    if (!enqueue(&b->downloadQueue, url)) {
        printf("Download tidak diterima, antrian sudah penuh.\n"); // [11]
    }
}

void cmdTick(Browser *b) {
    if (isQueueEmpty(&b->downloadQueue)) {
        printf("Antrian download saat ini kosong.\n"); // [11]
        return;
    }
    tickQueue(&b->downloadQueue); // S02 STI: Menampilkan pesan selesai [12]
}

void cmdShowQueue(Browser *b) {
    printQueue(&b->downloadQueue);
}

/* Rumus Tick: (length(URL) / 5) + 2 [9] */
int calculateTicks(const char *url) {
    return (strlen(url) / 5) + 2;
}
