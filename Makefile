bin/build : lib/main.o lib/hashairlines.o lib/hashairports.o lib/structures.o lib/reader.o
	gcc lib/main.o lib/hashairports.o lib/hashairlines.o lib/structures.o lib/reader.o -o bin/build

lib/hashairlines.o : hashFunc/hashairlines.c
	gcc -c -g -w -Wall -Wextra hashFunc/hashairlines.c -o lib/hashairlines.o

lib/hashairports.o : hashFunc/hashairports.c
	gcc -c -g -w -Wall -Wextra hashFunc/hashairports.c -o lib/hashairports.o

lib/structures.o : src/structures.c
	gcc -c -g -w -Wall -Wextra src/structures.c -o lib/structures.o

lib/reader.o : src/reader.c
	gcc -c -g -w -Wall -Wextra src/reader.c -o lib/reader.o

lib/main.o : src/main.c
	gcc -c -g -w -Wall -Wextra src/main.c -o lib/main.o
