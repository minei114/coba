#ifndef GRAPH_H
#define GRAPH_H
#include "types.h"
#include "adt_set.h"

/* Struktur Node untuk Linked List relasi (Adjacency List) [1] */
typedef struct Node {
    int target_id;
    struct Node* next;
} Node;

/* ADT Graph untuk menyimpan Web Graph [1] */
typedef struct {
    Node* adjList[MAX_WEB_PAGES + 1];
} Graph;

void graphInit(Graph* G);
void graphAddEdge(Graph* G, int src_id, int dest_id);
void graphDisplayLinkedPages(Graph* G, int src_id, WebPageSet* database);
const char* graphGetLinkedUrl(Graph* G, int src_id, int user_choice_index, WebPageSet* database);
void graphRemovePageRelations(Graph* G, int deleted_id);
boolean graphIsNumericValid(const char* str);

#endif
