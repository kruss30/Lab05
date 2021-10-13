#include <iostream>
#include <vector>
#include "StringData.h"
#include <string.h>

int linearSearch(std::vector<std::string> dataSet, std::string element)
{
    for (int i = 0; i < dataSet.size(); i++) {
        if (dataSet[i] == element) {
            return i;
        }
    }
    return -1;
}

int binarySearch(std::vector<std::string> dataSet, std::string element)
{
    int low, mid, high;
    high = dataSet.size()-1;
    low = 0;

    while (high >= low) {
        mid = (low + (high-low)/2);
        if (element.compare(dataSet[mid]) == 1) {
            low = mid + 1;
        } else if (element.compare(dataSet[mid]) == -1) {
            high = mid - 1;
        } else if (element.compare(dataSet[mid]) == 0) {
            return mid;
        }
    }

    return -1;
}

int main() {

    int linearSearch(std::vector<std::string> dataSet, std::string element);
    int binarySearch(std::vector<std::string> dataSet, std::string element);
    //Save data to a variable that way it isn't regenerated at every single run
    std::vector<std::string> dataArray = getStringData();

    long start;
    long end;
    long timeDifference;

    std::string search1 = "not_here";
    std::string search2 = "mzzzz";
    std::string search3 = "aaaaa";


    //linear search for "not_here"
    start = systemTimeNanoseconds();
    linearSearch(dataArray, search1);
    std::cout << "Beginning time for linear search 1: " << start;

    end = systemTimeNanoseconds();
    std::cout << "End of first linear method: " << end;

    timeDifference = end - start;
    std::cout << "Time difference for linear search 1: " << timeDifference;

    //binary search for "not_here"
    start = systemTimeNanoseconds();
    binarySearch(dataArray, search1);
    std::cout << "Beginning time for binary search 1: " << start;

    end = systemTimeNanoseconds();
    std::cout << "End of first binary method: " << end;

    timeDifference = end - start;
    std::cout << "Time difference for binary search 1: " << timeDifference;

    //linear search for "mzzzz"
    start = systemTimeNanoseconds();
    linearSearch(dataArray, search2);
    std::cout << "Beginning time for linear search 2: " << start;

    end = systemTimeNanoseconds();
    std::cout << "End of second linear method: " << end;

    timeDifference = end - start;
    std::cout << "Time difference for linear search 2: " << timeDifference;

    //binary search for "mzzzz"
    start = systemTimeNanoseconds();
    binarySearch(dataArray, search2);
    std::cout << "Beginning time for binary search 2: " << start;

    end = systemTimeNanoseconds();
    std::cout << "End of second binary method: " << end;

    timeDifference = end - start;
    std::cout << "Time difference for binary search 2: " << timeDifference;

    //linear search for "aaaaa"
    start = systemTimeNanoseconds();
    linearSearch(dataArray, search3);
    std::cout << "Beginning time for linear search 3: " << start;

    end = systemTimeNanoseconds();
    std::cout << "End of third linear method: " << end;

    timeDifference = end - start;
    std::cout << "Time difference for linear search 3: " << timeDifference;

    //binary search for "aaaaa"
    start = systemTimeNanoseconds();
    binarySearch(dataArray, search3);
    std::cout << "Beginning time for binary search 3: " << start;

    end = systemTimeNanoseconds();
    std::cout << "End of third binary method: " << end;

    timeDifference = end - start;
    std::cout << "Time difference for binary search 3: " << timeDifference;

    return 0;
}
