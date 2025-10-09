#include <stdlib.h>
#include <stdbool.h>

bool* kidsWithCandies(int* , int, int, int* );

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    if (!candies) return NULL;
    if (returnSize) *returnSize = candiesSize;

    bool* is_greater = (bool *)malloc(candiesSize * sizeof(bool));

    size_t max = candies[0];
    for (int i = 0; i < candiesSize; i++) {
        if (candies[i] > max)
            max = candies[i];
    }

    for (int i = 0; i < candiesSize; i++) {
        if ((candies[i] + extraCandies) >= max) {
            is_greater[i] = true;
        } else {
            is_greater[i] = false;
        }
    }

    return is_greater;
}