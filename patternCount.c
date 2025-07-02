#include <stdio.h>
#include <string.h>

int pattern_count(char *text, char *pattern) {
    int count = 0;
    int text_len = strlen(text);
    int pat_len = strlen(pattern);
    
    if (pat_len == 0 || pat_len > text_len)
        return 0;

    for (int i = 0; i <= text_len - pat_len; i++) {
        int match = 1;
        for (int j = 0; j < pat_len; j++) {
            if (text[i + j] != pattern[j]) {
                match = 0;
                break;
            }
        }
        if (match) count++;
    }
    return count;
}
