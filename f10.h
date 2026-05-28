#ifndef F10_H
#define F10_H

#include "browser.h"

/* Perintah untuk mengelola antrean download (F10) */
void cmdDownload(Browser *b, const char *url);
void cmdTick(Browser *b);
void cmdShowQueue(Browser *b);

#endif
