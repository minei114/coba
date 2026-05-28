#ifndef UTILS_H
#define UTILS_H
#include "types.h"

void lcgSetSeed(unsigned int seed);
unsigned int lcgRand(unsigned int max);
int startsWith(const char *str, const char *prefix);
int binarySearchURL(WebPage pages[], int size, const char* target);
#endif
