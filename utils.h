#ifndef UTILS_H
#define UTILS_H
#include "types.h"

void lcgSetSeed(unsigned int seed);
unsigned int lcgRand(unsigned int max);
int binarySearchURL(WebPage pages[], int size, const char* target); // Wajib STI
int strCmp(const char *a, const char *b);
#endif
