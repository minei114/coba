#ifndef CMD_PAGES_H
#define CMD_PAGES_H

#include "browser.h"

void cmdAddPage(Browser *b, const char *url);
void cmdDeletePage(Browser *b, const char *url);

#endif
