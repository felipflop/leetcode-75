#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define VOWELS 10

char* reverse_vowels(char *);
bool is_vowel(char);

char* reverse_vowels(char* s) {
    if (!s) return NULL;
    size_t len = strlen(s);

    /* Count number of vowels */
    size_t vowel_count = 0;
    for (size_t i = 0; i < len; ++i) {
        if (is_vowel(s[i]))
            ++vowel_count; 
    }

    if (vowel_count == 0) return s;

    char *vals = malloc(vowel_count * sizeof(char));        
    size_t *idxs = malloc(vowel_count * sizeof(size_t));    

    if (!vals || !idxs) {                                  
        free(vals);
        free(idxs);
        return s; // return original string to avoid crash 
    }

    size_t j = 0;
    for (size_t i = 0; i < len; ++i) {
        if (is_vowel(s[i])) {
            vals[j] = s[i];   
            idxs[j] = i;      
            ++j;
        }
    }

    /* Reverse vowels */
    size_t k = vowel_count - 1;
    for (size_t i = 0; i < vowel_count; ++i) {
        s[idxs[i]] = vals[k--];
    }

    free(vals);
    free(idxs);

    return s;
}

bool is_vowel(char s) {
    const char vowel_lut[] = {
        'a', 'e', 'i', 'o', 'u', 
        'A', 'E', 'I', 'O', 'U', 
    };

    for (int i = 0; i < VOWELS; ++i) {
        if (s == vowel_lut[i])
            return true;
    }

    return false;
}