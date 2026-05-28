#include "adt_array.h"
#include <stdio.h>
#include <string.h>

void tabArrayInit(TabArray *ta) {
    ta->size = 1;
    ta->currentTab = 0;
    ta->tabCounter = 1;
    for (int i = 0; i < TABS_MAX_AMOUNT; i++) ta->tabs[i].active = FALSE;
    
    // Inisialisasi TAB1 default [9]
    ta->tabs.active = TRUE;
    strcpy(ta->tabs.name, "TAB1");
    CreateNav(&ta->tabs.nav);
}

int tabAdd(TabArray *ta) {
    if (ta->size >= TABS_MAX_AMOUNT) {
        printf("ERROR: Jumlah tab tidak bisa melebihi batas maksimum!\n");
        return 0;
    }
    for (int i = 0; i < TABS_MAX_AMOUNT; i++) {
        if (!ta->tabs[i].active) {
            ta->tabCounter++;
            ta->tabs[i].active = TRUE;
            sprintf(ta->tabs[i].name, "TAB%d", ta->tabCounter);
            CreateNav(&ta->tabs[i].nav);
            ta->size++;
            printf("Tab baru (%s) berhasil dibuat!\n", ta->tabs[i].name);
            return 1;
        }
    }
    return 0;
}

int tabMove(TabArray *ta, int direction, int steps) {
    // Logika perpindahan antar tab aktif [10, 11]
    int activeIdx[TABS_MAX_AMOUNT], count = 0, currentPos = -1;
    for (int i = 0; i < TABS_MAX_AMOUNT; i++) {
        if (ta->tabs[i].active) {
            if (i == ta->currentTab) currentPos = count;
            activeIdx[count++] = i;
        }
    }
    int target = currentPos + (direction * steps);
    if (target < 0 || target >= count) {
        printf("ERROR: Posisi tab tidak valid!\n");
        return 0;
    }
    ta->currentTab = activeIdx[target];
    printf("Tab saat ini berhasil diganti ke %s.\n", ta->tabs[ta->currentTab].name);
    return 1;
}
