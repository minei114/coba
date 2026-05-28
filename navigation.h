#ifndef NAVIGATION_H
#define NAVIGATION_H

#include "types.h"

/* ADT Stack untuk navigasi per tab */
typedef struct {
    char buffer[TAB_HISTORY_MAX][MAX_URL_LEN];
    int idxTop;       /* index tertinggi di stack */
    int currentIndex; /* posisi halaman saat ini */
} Navigation;

void CreateNav(Navigation *N);

/* Push halaman baru. Hapus forward history jika berada di tengah */
void pushNewPage(Navigation *N, const char *url);

/* Mundur 1 langkah */
void stepBack(Navigation *N, char *outUrl);

/* Maju 1 langkah */
void stepForward(Navigation *N, char *outUrl);

#endif
