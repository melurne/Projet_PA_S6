bin/build : lib/main.o lib/hashairlines.o lib/hashairports.o lib/structures.o lib/reader.o lib/sorter.o lib/requests.o
	gcc lib/main.o lib/hashairports.o lib/hashairlines.o lib/structures.o lib/reader.o lib/sorter.o lib/requests.o -o bin/build

lib/hashairlines.o : hashFunc/hashairlines.c
	gcc -c -g -w -Wall -Wextra hashFunc/hashairlines.c -o lib/hashairlines.o

lib/hashairports.o : hashFunc/hashairports.c
	gcc -c -g -w -Wall -Wextra hashFunc/hashairports.c -o lib/hashairports.o

lib/structures.o : src/structures.c src/structures.h
	gcc -c -g -w -Wall -Wextra src/structures.c -o lib/structures.o

lib/reader.o : src/reader.c
	gcc -c -g -w -Wall -Wextra src/reader.c -o lib/reader.o

lib/sorter.o : src/sorter.c
	gcc -c -g -w -Wall -Wextra src/sorter.c -o lib/sorter.o

lib/requests.o : src/requests.c
	gcc -c -g -w -Wall -Wextra src/requests.c -o lib/requests.o

lib/main.o : src/main.c
	gcc -c -g -w -Wall -Wextra src/main.c -o lib/main.o
