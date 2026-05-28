#include "utils.h"
#include <string.h>

static unsigned int _seed = 1;

/* Implementasi LCG [7] */
void lcgSetSeed(unsigned int seed) { 
    _seed = seed; 
}

unsigned int lcgRand(unsigned int max) {
    _seed = (unsigned int)((1103515245ull * _seed + 12345ull) & 0x7fffffff);
    return _seed % max;
}

/* E01: Validasi URL Manual (Regex: ^(?!-)[A-Za-z0-9-]{1,63}(?<!-)(\.[A-Za-z]{2,})+) [5] */
int isValidURL(const char *url) {
    int len = strlen(url);
    if (len == 0 || url == '-' || url[len-1] == '-') return 0;

    int dotCount = 0;
    for (int i = 0; i < len; i++) {
        if (url[i] == '.') dotCount++;
        else if (!((url[i] >= 'a' && url[i] <= 'z') || 
                   (url[i] >= 'A' && url[i] <= 'Z') || 
                   (url[i] >= '0' && url[i] <= '9') || 
                   url[i] == '-')) {
            return 0;
        }
    }
    return (dotCount >= 1);
}

/* E02: Validasi Numerik (Positif, Max 6 digit/999999) [5] */
int isPositiveInt(const char *s) {
    int len = strlen(s);
    if (len == 0 || len > 6) return 0;
    for (int i = 0; i < len; i++) {
        if (s[i] < '0' || s[i] > '9') return 0;
    }
    return 1;
}

/* STI: Wajib Binary Search [8] */
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

void trimNewline(char *s) {
    int len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') s[len - 1] = '\0';
}

int startsWith(const char *str, const char *prefix) {
    return strncmp(str, prefix, strlen(prefix)) == 0;
}
