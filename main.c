#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

/* Function to compare two postal codes (int) */
int compareCodes(void *init, void *toCompare) {
  return (*((int*) init) == *((int*) toCompare));
}


int main(int argc, char const *argv[])
{

  typedef struct
  {
    int code;
    List list;
  } PostalCode;

  FILE *f;
  char line[45]; /* whole line ("city code") */
  char city[40]; /* city name on a line */
  int code; /* postal code on a line */
  int slot; /*slot for finding function */
  
  /* List of all postal codes with their cities */
  List lpostalCodes = list_initialize();

  /* A postal code structure containing the code and the cities */
  PostalCode *pc;

  /* Opening of the file */
  if (argc < 2)
    return 42;
  f = fopen(argv[1], "r");

  if (f == NULL) {
    exit(1);
  }


  while (fgets(line, 81, f) != NULL)
  {
    /* Processing of each line */
    if (sscanf(line, "%s%d", city, &code) == 2) /* makes sure the line is formatted as "... ..." */
    {
      if ((slot = list_find(lpostalCodes, &code, &compareCodes)) == -1) /* postal code not found: add new element to global list */
      {
        pc = (PostalCode *) malloc(sizeof(PostalCode));
        pc->code = code;
        pc->list = list_tailInsertion(NULL, (void *) strdup(city));
        lpostalCodes = list_tailInsertion(lpostalCodes, pc);
      }
      else /* add city to the cities list of the nth element */
      {
        /* aller à l'élément du nth pointeur de la liste */
        /* au nth élément : prendre la liste des villes et faire un tailinsertion */
        pc = list_getElement(lpostalCodes, slot);
        pc->list = list_tailInsertion(pc->list, (void *) strdup(city));
      }
    }
    else 
      printf("Incorrect format\n");
  }
  
  fclose(f);


  List tmp = lpostalCodes;

  /* Get all postal codes with more than 1 city & print them */
  while (lpostalCodes != NULL) /* go through whole postal codes list */
  {
    pc = lpostalCodes->elt; 
    List tmppc = pc->list;

    // if (pc->list->next) { /* Uncomment to display only postal codes with more than 1 city */
      printf("%d\n", pc->code);

      while (pc->list != NULL) {
        printf("%s\n", ((char *) pc->list->elt));

        free(pc->list->elt);
        pc->list = pc->list->next;
        free(tmppc);
        tmppc = pc->list;
      }
    // }

    free(lpostalCodes->elt);
    lpostalCodes = lpostalCodes->next;
    free(tmp);
    tmp = lpostalCodes;
  }
  

  return 0;
}
