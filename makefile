bin/build : lib/main.o lib/hashairlines.o lib/hashairports.o
	gcc lib/main.o lib/hashairports.o lib/hashairlines.o -o bin/build

lib/hashairlines.o : hashFunc/hashairlines.c
	gcc -c -w -Wall -Wextra hashFunc/hashairlines.c -o lib/hashairlines.o

lib/hashairports.o : hashFunc/hashairports.c
	gcc -c -w -Wall -Wextra hashFunc/hashairports.c -o lib/hashairports.o

lib/main.o : src/main.c
	gcc -c -w -Wall -Wextra src/main.c -o lib/main.o
