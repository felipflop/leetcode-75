#include <stdlib.h>
#include <stdint.h>

char* mergeAlternately(char*, char*);

char* mergeAlternately(char* word1, char* word2) {
    if (!word1 || !word2) return NULL;

    size_t len1 = 0, len2 = 0;
    while (word1[len1] != '\0') 
        len1++;
    while (word2[len2] != '\0') 
        len2++;

    size_t total_len = len1 + len2 + 1; // +1 for null terminator
    char* merged_word = (char *)malloc(total_len * sizeof(char));
    
    if (!merged_word) 
        return NULL;

    /* Merge two words alternately */
    size_t i = 0, j = 0, k = 0;
    while (i < len1 && j < len2) {
        merged_word[k++] = word1[i++];
        merged_word[k++] = word2[j++];
    }

    /* Fill in tail end with remaining word */
    while (i < len1) 
        merged_word[k++] = word1[i++];
    
    while (j < len2) 
        merged_word[k++] = word2[j++];
    
    merged_word[k] = '\0';
    return merged_word;
}