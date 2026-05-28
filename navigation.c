#include "navigation.h"
#include <string.h>

void pushNewPage(Navigation *N, const char *url) {
    // F07: Potong history forward jika kursor tidak di puncak [8, 12]
    if (N->currentIndex != IDX_UNDEF && N->currentIndex < N->idxTop) {
        N->idxTop = N->currentIndex;
    }
    if (N->idxTop < TAB_HISTORY_MAX - 1) {
        N->idxTop++;
        N->currentIndex = N->idxTop;
        strcpy(N->buffer[N->idxTop], url);
    }
}
history_view.c
#include "history_view.h"
#include <stdio.h>

void displayTabHistory(Navigation N) {
    if (N.idxTop == IDX_UNDEF) {
        printf("Riwayat kosong.\n");
        return;
    }
    for (int i = 0; i <= N.idxTop; i++) {
        printf("[%d] %s", i, N.buffer[i]);
        if (i == N.currentIndex) printf(" <- YOU ARE HERE"); // Penanda posisi [13, 14]
        printf("\n");
    }
}

void jumpBack(Navigation *N, int steps, char *outUrl) {
    if (N->currentIndex - steps < 0) {
        printf("ERROR: BACK TIDAK BISA DIJALANKAN!\n");
        return;
    }
    N->currentIndex -= steps;
    strcpy(outUrl, N->buffer[N->currentIndex]);
}
