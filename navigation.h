#ifndef NAVIGATION_H
#define NAVIGATION_H
#include "types.h"

/* ADT Stack untuk navigasi per tab */
typedef struct {
    char buffer[TAB_HISTORY_MAX][MAX_URL_LEN];
    int idxTop;       /* Elemen tertinggi di stack */
    int currentIndex; /* Posisi user sekarang */
} Navigation;

void CreateNav(Navigation *N);
/* Push halaman baru. Hapus history ke depan jika kursor di tengah */
void pushNewPage(Navigation *N, const char *url);
/* Mundur/Maju 1 langkah */
void stepBack(Navigation *N, char *outUrl);
void stepForward(Navigation *N, char *outUrl);

#endif
