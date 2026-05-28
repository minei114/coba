#ifndef HISTORY_VIEW_H
#define HISTORY_VIEW_H
#include "navigation.h"

/* Menampilkan daftar URL dalam riwayat tab aktif dengan penanda posisi */
void displayTabHistory(Navigation N);

/* Mundur sebanyak steps (X) dan mengembalikan URL posisi baru */
void jumpBack(Navigation *N, int steps, char *outUrl);

/* Maju sebanyak steps (X) dan mengembalikan URL posisi baru */
void jumpForward(Navigation *N, int steps, char *outUrl);

#endif
