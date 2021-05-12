#ifndef LIST_H
#define LIST_H

typedef struct Cell
{
  void *elt;
  struct Cell *next;
} Cell;

typedef struct Cell *List;

void list_display(List);

List list_initialize();

int list_isEmpty(List);

List list_headInsertion(List, void *);

List list_headDeletion(List);

List list_tailInsertion(List, void *);

List list_middleInsertion(List, int, void *);

int list_find(List l, void *c, int (* function)(void *, void *));

void* list_getElement(List, int);

List list_free(List);

int list_getSize(List);


#endif /* LIST_H */
