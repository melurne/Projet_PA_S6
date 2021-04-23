#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define NK  14       /* number of keys */
#define NG  21       /* number of vertices */
#define NS  2       /* length of salt strings */

int G[] = {0, 0, 0, 10, 0, 0, 15, 17, 11, 0, 4, 18, 16, 5, 12, 0, 
    3, 9, 13, 0, 1};

char *K[] = {"UA", "AA", "US", "F9", "B6", "OO", "AS", "NK", "WN", 
    "DL", "EV", "HA", "MQ", "VX"};


/* return index of key in K if key is found, -1 otherwise */
int get_index(const char *key)
{
    int f1 = 0, f2 = 0, i;

    for (i = 0; key[i] != '\0' && i < NS; i++) {
        f1 += "j3"[i] * key[i];
        f2 += "OY"[i] * key[i];
    }
    i = (G[f1 % NG] + G[f2 % NG]) % NG;
    if (i < NK && strcmp(key, K[i]) == 0)
        return i;

    return -1;
}

int main()
{
    int i;
    char *junk[] = {"ACASSICUHAIUSCSACASCASKHCKJHSAKJCHK827349RFEWIHIWUE",
                    "abc", "x", "99"};

    for (i = 0; i < 4; i++)
        assert(get_index(junk[i]) == -1);

    for (i = 0; i < NK; i++)
        assert(get_index(K[i]) == i);

    printf("OK\n");
    return 0;
}
