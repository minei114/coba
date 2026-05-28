#ifndef F10_H
#define F10_H

#include "browser.h"

/* Perintah untuk mengelola antrean download (F10) */
void cmdDownload(BrowserState *bs, const char *url);
void cmdTick(BrowserState *bs);
void cmdShowQueue(BrowserState *bs);

#endif
