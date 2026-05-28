#ifndef ADT_ARRAY_H
#define ADT_ARRAY_H
#include "types.h"
#include "navigation.h"   /* Navigation untuk F07/F08 */

/* ADT TAB - Satu tab browser */
typedef struct {
    char       name[4];    /* "TAB1", "TAB2", dst */
    Navigation nav;         /* navigasi per tab */
    boolean    active;      /* status tab terbuka */
} Tab;

/* ADT TABARRAY - Kumpulan semua tab */
typedef struct {
    Tab  tabs[TABS_MAX_AMOUNT];
    int  size;        /* jumlah tab aktif */
    int  currentTab;  /* indeks tab aktif */
    int  tabCounter;  /* untuk penamaan otomatis */
} TabArray;

/* Operasi TabArray */
void tabArrayInit(TabArray *ta);
int tabAdd(TabArray *ta);
int tabClose(TabArray *ta);
int tabMove(TabArray *ta, int direction, int steps);
void tabPrint(TabArray *ta);
Tab *tabGetCurrent(TabArray *ta);

/* Operasi History (wrapper ke Navigation) */
int tabPushHistory(TabArray *ta, const char *url);
const char *tabCurrentUrl(TabArray *ta);

#endif
