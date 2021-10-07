#include <iostream>
#include <vector>
#include "StringData.h"

int main() {
    int linearSearch(std::vector<std::string> datatSet, std::string element);
    int binarySearch(std::vector<std::string> datatSet, std::string element);

    std::string message = "not_here";

    long start = systemTimeNanoseconds();
    binarySearch(getStringData(), message);
    long end = systemTimeNanoseconds();
    std::cout << "\nBinary Search Time: " << end-start;
    start = systemTimeNanoseconds();
    linearSearch(getStringData(), message);
    end = systemTimeNanoseconds();
    std::cout << "\nLinear Search Time: " << end-start;

    message = "mzzzz";
    start = systemTimeNanoseconds();
    binarySearch(getStringData(), message);
    end = systemTimeNanoseconds();
    std::cout << "\nBinary Search Time: " << end-start;
    start = systemTimeNanoseconds();
    linearSearch(getStringData(), message);
    end = systemTimeNanoseconds();
    std::cout << "\nLinear Search Time: " << end-start;

    message = "aaaaa";
    start = systemTimeNanoseconds();
    binarySearch(getStringData(), message);
    end = systemTimeNanoseconds();
    std::cout << "\nBinary Search Time: " << end-start;
    start = systemTimeNanoseconds();
    linearSearch(getStringData(), message);
    end = systemTimeNanoseconds();
    std::cout << "\nLinear Search Time: " << end-start;

    return 0;
}

int linearSearch(std::vector<std::string> dataSet, std::string element) {
    for (int i = 0; i < dataSet.size(); i++) {
        if (dataSet[i] == element) {
            return i;
        }
    }
    return -1;
}

int binarySearch(std::vector<std::string> datatSet, std::string element) {
    int low,mid,high;
    high = datatSet.size()-1;
    low = 0;

    while (high >= low) {
        mid = (low + (high-low)/2);
        if (element > datatSet[mid]) {
            low = mid + 1;
        } else if (element < datatSet[mid]) {
            high = mid - 1;
        } else if (element == datatSet[mid]) {
            return mid;
        }
    }

    return -1;
}