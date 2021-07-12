CC=gcc
CFLAGS=-Wall

busca: Arvore_A.o main.o
	$(CC) -o busca Arvore_A.o main.o