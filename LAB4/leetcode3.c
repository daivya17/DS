#include <stdio.h>
#include <string.h>

bool backspaceCompare(char* s, char* t) {
    char s1[1000];
    char s2[1000];
    int i = 0, j = 0; 
    for (int k = 0; k < strlen(s); k++) {
        if (s[k] == '#') {
            if (i > 0) {
                --i;
            }
        } else {
            s1[i++] = s[k];
        }
    }
    s1[i] = '\0';
    for (int k = 0; k < strlen(t); k++) {
        if (t[k] == '#') {
            if (j > 0) {
                --j;
            }
        } else {
            s2[j++] = t[k];
        }
    }
    s2[j] = '\0';
    return strcmp(s1, s2) == 0;
}
