#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void sortMixedArray() {
    void *arr[] = { (void *)12, (void *)9, (void *)30, "A", "M", (void *)99, (void *)82, "J", "N", "B" };
    char *letters[10];
    int numbers[10];
    int i, l = 0, n = 0;

    for (i = 0; i < 10; i++) {
        if ((int)(size_t)arr[i] <= 999 && (int)(size_t)arr[i] > 0) {
            numbers[n++] = (int)(size_t)arr[i];
        } else {
            letters[l++] = (char *)arr[i];
        }
    }

    // Sort letters
    for (i = 0; i < l-1; i++)
        for (int j = i+1; j < l; j++)
            if (strcmp(letters[i], letters[j]) > 0) {
                char *tmp = letters[i];
                letters[i] = letters[j];
                letters[j] = tmp;
            }

    // Sort numbers
    for (i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (numbers[i] > numbers[j]) {
                int tmp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = tmp;
            }

    printf("Sorted result: [");
    for (i = 0; i < l; i++) printf("\"%s\"%s", letters[i], (i < l+n-1 ? ", " : ""));
    for (i = 0; i < n; i++) printf("%d%s", numbers[i], (i < n-1 ? ", " : ""));
    printf("]\n");
}
