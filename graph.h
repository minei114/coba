typedef struct Node {
    int target_id;
    struct Node* next;
} Node;

typedef struct {
    Node* adjList[MAX_WEB_PAGES + 1];
} Graph;

void graphAddEdge(Graph* G, int src_id, int dest_id); // [9]
void graphRemovePageRelations(Graph* G, int deleted_id); // [10]

--------------------------------------------------------------------------------
5. Fitur F06, F07, F08: adt_array.h/c dan navigation.h/c
Mengelola tab (ADT Array) dan navigasi back/forward (ADT Stack)
.
navigation.c
void pushNewPage(Navigation *N, const char *url) {
    if (N->currentIndex < N->idxTop) N->idxTop = N->currentIndex; // Potong forward history [13]
    if (N->idxTop < TAB_HISTORY_MAX - 1) {
        N->idxTop++;
        N->currentIndex = N->idxTop;
        strcpy(N->buffer[N->idxTop], url);
    }
}
