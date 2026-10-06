CC ?= gcc

CFLAGS=-Wall -Wextra -g

COBJS ?= client.o
SOBJS ?= serveur.o
ROBJS ?= repertoire.o

.SUFFIXES: .c .o

SERVER = serveur
CLIENT = client
REPERTOIRE = repertoire

all: $(SERVER) $(CLIENT) $(REPERTOIRE)

$(SERVER): $(SOBJS)
	$(CC) -o $(SERVER) $(SOBJS)

$(CLIENT): $(COBJS)
	$(CC) -o $(CLIENT) $(COBJS)

$(REPERTOIRE): $(ROBJS)
	$(CC) -o $(REPERTOIRE) $(ROBJS)

.c.o:
	$(CC) $(CFLAGS) -c $*.c

clean:
	rm -f *.o $(SERVER) $(CLIENT) $(REPERTOIRE)
