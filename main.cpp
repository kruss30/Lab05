#include <iostream>
#include <vector>
#include "StringData.h"
#include <string.h>

int main() {
    int linearSearch(std::vector<std::string> datatSet, std::string element);
    int binarySearch(std::vector<std::string> datatSet, std::string element);
    //Save data to a variable that way it isn't regenerated at every single run
    std::vector<std::string> data = getStringData();

    std::string message = "not_here";

    long start = systemTimeNanoseconds();
    binarySearch(data, message);
    long end = systemTimeNanoseconds();
    std::cout << "\nBinary Search Time: " << end-start;
    start = systemTimeNanoseconds();
    linearSearch(data, message);
    end = systemTimeNanoseconds();
    std::cout << "\nLinear Search Time: " << end-start;

    message = "mzzzz";
    start = systemTimeNanoseconds();
    binarySearch(data, message);
    end = systemTimeNanoseconds();
    std::cout << "\nBinary Search Time: " << end-start;
    start = systemTimeNanoseconds();
    linearSearch(data, message);
    end = systemTimeNanoseconds();
    std::cout << "\nLinear Search Time: " << end-start;

    message = "aaaaa";
    start = systemTimeNanoseconds();
    binarySearch(data, message);
    end = systemTimeNanoseconds();
    std::cout << "\nBinary Search Time: " << end-start;
    start = systemTimeNanoseconds();
    linearSearch(data, message);
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
        if (element.compare(datatSet[mid]) == 1) {
            low = mid + 1;
        } else if (element.compare(datatSet[mid]) == -1) {
            high = mid - 1;
        } else if (element.compare(datatSet[mid]) == 0) {
            return mid;
        }
    }

    return -1;
}