#include "utils.h"
#include <string.h>

static unsigned int _seed = 1;
void lcgSetSeed(unsigned int seed) { _seed = seed; }
unsigned int lcgRand(unsigned int max) {
    _seed = (unsigned int)((1103515245ull * _seed + 12345ull) & 0x7fffffff);
    return _seed % max;
}

// Implementasi Binary Search untuk STI (Asumsi array sudah terurut berdasarkan URL)
int binarySearchURL(WebPage pages[], int size, const char* target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int res = strcmp(pages[mid].url, target);
        if (res == 0) return mid;
        if (res < 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
