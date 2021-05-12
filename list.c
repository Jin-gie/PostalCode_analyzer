#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"


void list_display(List l) {
    while (l != NULL) {
        printf("%p\n", l->elt);
        l = l->next;
    }
    printf("\n");
}

List list_initialize() {
    return(NULL);
}

int list_isEmpty(List l) {
    return (l == NULL);
}

List list_headInsertion(List l, void *e) {
    List p;
    p = (List) malloc(sizeof(Cell));
    if (p == NULL) {
        printf("Allocation impossible...");
        exit(1);
    }
    p->elt = e;
    p->next = l;

    return (p);
}


List list_headDeletion(List l) {
    List p = NULL;
    if (!list_isEmpty(l)) {
        p = p->next;
        free(l);
    }

    return (p);
}

List list_tailInsertion(List l, void *e) {
    List lOrigin;
    if (list_isEmpty(l))
        return (list_headInsertion(l, e));
    
    lOrigin = l;

    while (l->next != NULL)
        l = l->next;

    List p;
    p = (List) malloc(sizeof(Cell));
    if (p == NULL) {
        printf("Allocation impossible...\n");
        exit(1);
    }

    p->elt = e;
    p->next = NULL;

    l->next = p;
    return(lOrigin);
    
}

int list_find(List l, void *c, int (* function)(void *, void *)) {
    int cpt = 0;
    List lOrigin = l;

    while (lOrigin) {
        if (function(lOrigin->elt, c))
            return cpt;
        cpt++;
        lOrigin = lOrigin->next;
    }

    return -1;
}

void* list_getElement(List l, int slot) {
    int i;
    List lOrigin = l;

    if (!list_isEmpty(lOrigin)) 
    {
        for (i = 0; i < slot; i++)
        {
            lOrigin = lOrigin->next;
        }
        return lOrigin->elt;
    }

    return NULL;
}