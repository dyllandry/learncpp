#include <algorithm>
#include <iostream>

int main() {
    int array[]{6, 3, 2, 9, 7, 1, 5, 4, 8};
    const int arrayLength =
        static_cast<int>(sizeof(array)) / static_cast<int>(sizeof(array[0]));

    // Sort array in place using bubble sort.
    for (int i{0}; i < arrayLength - 2; i++) {
        bool hasSwapped = false;
        for (int j{0}; j < arrayLength - 1 - i; j++) {
            const int number1 = array[j];
            const int number2 = array[j + 1];
            if (number1 > number2) {
                std::swap(array[j], array[j + 1]);
                hasSwapped = true;
            }
        }

        // If we haven't swapped this whole loop, then the array must already
        // be sorted. Break the sorting loop and continue.
        if (!hasSwapped) {
            break;
        }
    }

    // Print sorted array.
    for (int i{0}; i < arrayLength - 1; i++) {
        std::cout << array[i] << " ";
    }
    return 0;
}
