void cmdDiscover(WebPage pages[], int size) {
    int indices[MAX_WEB_PAGES], total = 0;
    for (int i = 0; i < MAX_WEB_PAGES; i++) {
        if (pages[i].active) indices[total++] = i;
    }
    if (total == 0) return;
    int show = (total < 5) ? total : 5;
    // Fisher-Yates shuffle menggunakan lcgRand
    for (int i = total - 1; i > 0; i--) {
        int j = lcgRand(i + 1);
        int tmp = indices[i];
        indices[i] = indices[j];
        indices[j] = tmp;
    }
    printf("Halaman yang mungkin menarik:\n");
    for (int i = 0; i < show; i++) printf("- %s\n", pages[indices[i]].url);
}
