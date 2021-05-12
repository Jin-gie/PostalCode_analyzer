# La variable EXTRA_OBJS a été ajoutée pour tenir compte qu'un
# fichier objet vous est fourni dans le cadre de cette évaluation.
# Utilisez de votre côté la variable OBJS comme vu en cours.

CC         = gcc
OBJS       = list.o main.o
CFLAGS     = -g -c -Wall
EXTRA_OBJS =
LDFLAGS    = 
PGM        = main

all: $(PGM)

$(PGM): $(OBJS)
	$(CC) -o $(PGM) $(OBJS) $(EXTRA_OBJS) $(LDFLAGS)

.c.o:
	$(CC) $(CFLAGS) $<

clean:
	rm -f $(PGM)
	rm -f $(OBJS)
	rm -f *~