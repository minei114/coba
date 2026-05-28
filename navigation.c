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
