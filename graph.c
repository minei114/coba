void graphDisplayLinkedPages(Graph* G, int src_id, WebPageSet* database) {
    Node* curr = G->adjList[src_id];
    int count = 1;

    while (curr != NULL) {

        for (int i = 0; i < MAX_WEB_PAGES; i++) {

            if (database->pages[i].id == curr->target_id &&
                database->pages[i].active) {

                printf("[%d] %s\n",
                       count++,
                       database->pages[i].url);
            }
        }

        curr = curr->next;
    }
}
