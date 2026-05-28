#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

void graphInit(Graph* G) {
    for (int i = 0; i <= MAX_WEB_PAGES; i++) G->adjList[i] = NULL;
}

void graphAddEdge(Graph* G, int src_id, int dest_id) {
    if (src_id < 0 || src_id > MAX_WEB_PAGES) return;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->target_id = dest_id;
    newNode->next = G->adjList[src_id];
    G->adjList[src_id] = newNode;
}

void graphDisplayLinkedPages(Graph* G, int src_id, WebPageSet* database) {
    Node* curr = G->adjList[src_id];
    int count = 1;
    while (curr != NULL) {
        //WebPage* wp = setSearchById(database, curr->target_id);
        if (wp != NULL && wp->active) {
            //printf("[%d] %s\n", count++, wp->url);
        }
        curr = curr->next;
    }
}

void graphRemovePageRelations(Graph* G, int deleted_id) {
    /* Hapus semua Link Keluar [6] */
    Node* curr = G->adjList[deleted_id];
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    G->adjList[deleted_id] = NULL;

    /* Hapus semua Link Masuk dari halaman lain [6, 7] */
    for (int i = 0; i <= MAX_WEB_PAGES; i++) {
        if (i == deleted_id) continue;
        Node* current = G->adjList[i];
        Node* prev = NULL;
        while (current != NULL) {
            if (current->target_id == deleted_id) {
                if (prev == NULL) G->adjList[i] = current->next;
                else prev->next = current->next;
                Node* toFree = current;
                current = current->next;
                free(toFree);
            } else {
                prev = current;
                current = current->next;
            }
        }
    }
}
