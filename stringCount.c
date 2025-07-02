#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char ch;
    int count;
} CharCount;

int compareChar(const void *a, const void *b) {
    return ((CharCount *)a)->ch - ((CharCount *)b)->ch;
}

void countLetters(const char *input) {
    CharCount map[256] = {0};
    int i, len = strlen(input), unique = 0;

    for (i = 0; i < len; i++) {
        char c = input[i];
        if (isalpha(c)) {
            if (map[(int)c].count == 0) {
                map[(int)c].ch = c;
                unique++;
            }
            map[(int)c].count++;
        }
    }

    CharCount result[unique];
    int idx = 0;
    for (i = 0; i < 256; i++) {
        if (map[i].count > 0)
            result[idx++] = map[i];
    }

    qsort(result, unique, sizeof(CharCount), compareChar);

    printf("Output: [");
    for (i = 0; i < unique; i++) {
        printf("\"%c\":%d", result[i].ch, result[i].count);
        if (i < unique - 1) printf(", ");
    }
    printf("]\n");
}
