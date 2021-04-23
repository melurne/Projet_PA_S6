#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define NKairlines 14 /* number of keys */
#define NGairlines 21 /* number of vertices */
#define NSairlines 2  /* length of salt strings */

int Gairlines[] = {0,  0,  0, 10, 0, 0, 15, 17, 11, 0, 4,
                   18, 16, 5, 12, 0, 3, 9,  13, 0,  1};

char* Kairlines[] = {"UA", "AA", "US", "F9", "B6", "OO", "AS",
                     "NK", "WN", "DL", "EV", "HA", "MQ", "VX"};

/* return index of key in K if key is found, -1 otherwise */
int get_index_airlines(const char* key) {
    int f1 = 0, f2 = 0, i;

    for (i = 0; key[i] != '\0' && i < NSairlines; i++) {
        f1 += "j3"[i] * key[i];
        f2 += "OY"[i] * key[i];
    }
    i = (Gairlines[f1 % NGairlines] + Gairlines[f2 % NGairlines]) % NGairlines;
    if (i < NKairlines && strcmp(key, Kairlines[i]) == 0)
        return i;

    return -1;
}
/*
int main()
{
    int i;
    char *junk[] = {"ACASSICUHAIUSCSACASCASKHCKJHSAKJCHK827349RFEWIHIWUE",
                    "abc", "x", "99"};

    for (i = 0; i < 4; i++)
        assert(get_index(junk[i]) == -1);

    for (i = 0; i < NKairlines; i++)
        assert(get_index(K[i]) == i);

    printf("OK\n");
    return 0;
}
*/
