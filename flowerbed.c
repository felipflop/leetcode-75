#include <stdlib.h>
#include <stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    if (!flowerbed) return false;
    if (n <= 0) return true;
    if (flowerbedSize <= 0) return false;

    size_t occurences = 0;

    if (flowerbedSize == 1) {
        if (flowerbed[0] == 0) ++occurences;
        return n <= occurences;
    }

    /* first slot */
    if (flowerbed[0] == 0 && flowerbed[1] == 0) {
        flowerbed[0] = 1;
        ++occurences;
    }

    /* interior slots */
    for (size_t i = 1; i + 1 < (size_t)flowerbedSize; i++) {
        if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
            flowerbed[i] = 1;
            ++occurences;
        }
    }

    /* last slot */
    if (flowerbed[flowerbedSize - 1] == 0 && flowerbed[flowerbedSize - 2] == 0) {
        flowerbed[flowerbedSize - 1] = 1;
        ++occurences;
    }

    return n <= occurences;
}