#include "history_view.h"
#include <stdio.h>
#include <string.h>

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
