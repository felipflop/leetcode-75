#include <stdlib.h>
#include <string.h>

char* gcdOfStrings(char*, char*);

char* gcdOfStrings(char* str1, char* str2) {
    if (!str1 || !str2)
        return NULL;

    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    /* Handle empty strings */
    if (len1 == 0 || len2 == 0) {
        char *empty = malloc(1);

        if (!empty) 
            return NULL;

        empty[0] = '\0';

        return empty;
    }

    /* Handle incompatibility */
    for (size_t t = 0; t < len1 + len2; ++t) {
        if (str1[t % len1] != str2[t % len2]) {
            char *empty = malloc(1);

            if (!empty) 
                return NULL;

            empty[0] = '\0';

            return empty;
        }
    }

    /* Euclidean algorithm on lengths */
    size_t a = len1, b = len2;
    while (b != 0) {
        size_t r = a % b;
        a = b;
        b = r;
    }
    size_t g = a; /* gcd(len1,len2) */

    /* Return the prefix of length g */
    char *result = malloc(g + 1);

    if (!result) 
        return NULL;

    memcpy(result, str1, g);
    result[g] = '\0';
    
    return result;
}