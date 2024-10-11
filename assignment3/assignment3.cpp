#include <iostream>
#include <limits>
#include "assignment3.h"


int minArray(const int* array, int length) {
      if (length <= 0) {
        return std::numeric_limits<int>::max(); // empty 
    }
    int min = array[0]; 
    for (int i = 1; i < length; i++) {
        if (array[i] < min) {
            min = array[i];  
        }
    }

    return min;
}

template <typename T>
T minArray(const T* array, int length) {
    if (length <= 0) {
        return std::numeric_limits<T>::max();  
            }

    T minValue = array[0]; 
    for (int i = 1; i < length; i++) {
        if (array[i] < minValue) {
            minValue = array[i];  
        }
    }

    return minValue;
}
int main() {
    int numbers[] = {10, 2, 8, -1, 34, 0, -23};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    int minValue = minArray(numbers, length);
    std::cout << "The minimum value in the integer array is: " << minValue << std::endl;

    double doubleArray[] = {3.1, 2.7, 4.1, 1.6};
    int doubleLength = sizeof(doubleArray) / sizeof(doubleArray[0]);

    double minDouble = minArray(doubleArray, doubleLength);
    std::cout << "The minimum value in the double array is: " << minDouble << std::endl;
// testing 
    Complex complexArray[] = {
        Complex(1.0, 2.0),
     };
    int complexSize = sizeof(complexArray) / sizeof(complexArray[0]);

    std::cout << "Complex numbers in the array:" << std::endl;
    for (int i = 0; i < complexSize; ++i) {
        std::cout << "Complex number " << i + 1 << ": " << complexArray[i] << std::endl;
    }

    return 0;
}