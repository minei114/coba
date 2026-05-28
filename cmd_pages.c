#include "browser.h"
#include <stdio.h>
#include <string.h>

/* F05 - Tambah Halaman Baru */
void cmdAddPage(Browser *b, const char *url) {
    char content[MAX_CONTENT_LEN], line[MAX_STR_LEN], linkedUrl[MAX_URL_LEN];
    int contentLen = 0;

    if (setSearch(&b->pages, url) != NULL) {
        printf("Sudah terdapat halaman dengan url %s. Gunakan url lain!\n", url);
        return;
    }

    printf("Masukkan konten (Akhiri dengan titik '.' di baris baru):\n");
    content = '\0';
    while (1) {
        printf(">>> ");
        if (fgets(line, sizeof(line), stdin) == NULL) break;
        trimNewline(line);
        if (strcmp(line, ".") == 0) break;
        strcat(content, line);
        strcat(content, "\n");
    }

    if (setInsert(&b->pages, url, content)) {
        WebPage *newPage = setSearch(&b->pages, url);
        printf("Masukkan linked pages (Ketik 'DONE' jika sudah selesai):\n");
        while (1) {
            printf(">>> ");
            if (fgets(linkedUrl, sizeof(linkedUrl), stdin) == NULL) break;
            trimNewline(linkedUrl);
            if (strcmp(linkedUrl, "DONE") == 0) break;

            WebPage *dest = setSearch(&b->pages, linkedUrl);
            if (dest) graphAddEdge(&b->graph, newPage->id, dest->id);
            else printf("URL tidak ditemukan!\n");
        }
        printf("Halaman %s berhasil ditambahkan!\n", url);
    }
}

/* F05 - Hapus Halaman */
void cmdDeletePage(Browser *b, const char *url) {
    WebPage *page = setSearch(&b->pages, url);
    if (page == NULL) {
        printf("Tidak ada halaman dengan url %s!\n", url);
        return;
    }

    int pageId = page->id;
    mapRemove(&b->cache, url); // Bersihkan cache [3, 4]
    graphRemovePageRelations(&b->graph, pageId); // STI: Bersihkan Adjacency List [1]
    setDelete(&b->pages, url); // Soft-delete [5]
    printf("Halaman %s berhasil dihapus!\n", url);
}
