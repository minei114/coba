#include "navigation.h"
#include <string.h>

void CreateNav(Navigation *N) {
    N->idxTop = -1;
    N->currentIndex = -1;

    for (int i = 0; i < TAB_HISTORY_MAX; i++) {
        N->buffer[i][0] = '\0';
    }
}

/* Push halaman baru */
void pushNewPage(Navigation *N, const char *url) {

    // kalau user ada di tengah history → hapus forward history
    if (N->currentIndex != -1 && N->currentIndex < N->idxTop) {
        N->idxTop = N->currentIndex;
    }

    // cek kapasitas stack
    if (N->idxTop < TAB_HISTORY_MAX - 1) {
        N->idxTop++;
        N->currentIndex = N->idxTop;
        strcpy(N->buffer[N->idxTop], url);
    }
}

/* Back */
void stepBack(Navigation *N, char *outUrl) {
    if (N->currentIndex > 0) {
        N->currentIndex--;
        strcpy(outUrl, N->buffer[N->currentIndex]);
    } else if (N->currentIndex >= 0) {
        strcpy(outUrl, N->buffer[N->currentIndex]);
    } else {
        outUrl[0] = '\0';
    }
}

/* Forward */
void stepForward(Navigation *N, char *outUrl) {
    if (N->currentIndex < N->idxTop) {
        N->currentIndex++;
        strcpy(outUrl, N->buffer[N->currentIndex]);
    } else if (N->currentIndex >= 0) {
        strcpy(outUrl, N->buffer[N->currentIndex]);
    } else {
        outUrl[0] = '\0';
    }
}
