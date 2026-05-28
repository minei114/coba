#ifndef UTILS_H
#define UTILS_H

#include "types.h"

/* ===================== */
/* Linear Congruential Generator (LCG) */
/* ===================== */
void lcgSetSeed(unsigned int seed);
unsigned int lcgRand(unsigned int max);

/* ===================== */
/* String Helpers */
/* ===================== */
int strLen(const char *s);
int strCmp(const char *a, const char *b);
void trimNewline(char *s);
int startsWith(const char *str, const char *prefix);

/* ===================== */
/* Validasi Input (E01 & E02) */
/* ===================== */
int isValidURL(const char *url);
int isPositiveInt(const char *s);

/* ===================== */
/* STI: Binary Search */
/* ===================== */
int binarySearchURL(WebPage pages[], int size, const char* target);

#endif
