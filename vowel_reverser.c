#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* reverse_vowels(char *);

static size_t count_vowels(char *);
static bool   is_vowel(unsigned char);
static void   collect_vowels(char *, char *, size_t *);

char* reverse_vowels(char* s) {
    if (!s) return NULL;

    /* Count number of vowels */
    size_t n_vowels = count_vowels(s);

    if (n_vowels == 0) return s;

    char* vals = malloc(n_vowels * sizeof(char));        
    size_t* idxs = malloc(n_vowels * sizeof(size_t));    

    if (!vals || !idxs) {                                  
        free(vals);
        free(idxs);
        return s; // return original string to avoid crash 
    }

    collect_vowels(s, vals, idxs);

    /* Reverse vowels */
    size_t k = n_vowels - 1;
    for (size_t i = 0; i < n_vowels; ++i) {
        s[idxs[i]] = vals[k--];
    }

    free(vals);
    free(idxs);

    return s;
}

static size_t count_vowels(char* str) {
    size_t vowel_count = 0;
    size_t len = strlen(str);

    for (size_t i = 0; i < len; ++i) {
        if (is_vowel(str[i]))
            ++vowel_count; 
    }

    return vowel_count;
}

static bool is_vowel(unsigned char c) {
    const char vowel_lut[] = {
        'a', 'e', 'i', 'o', 'u', 
        'A', 'E', 'I', 'O', 'U', 
    };
    size_t lut_len = sizeof(vowel_lut)/sizeof(vowel_lut[0]);

    for (size_t i = 0; i < lut_len; ++i) {
        if (c == vowel_lut[i])
            return true;
    }

    return false;
}

static void collect_vowels(char* str, char* vals, size_t* idxs) {
    size_t j = 0;
    size_t len = strlen(str);

    for (size_t i = 0; i < len; ++i) {
        if (is_vowel(str[i])) {
            vals[j] = str[i];   
            idxs[j] = i;      
            ++j;
        }
    }
}