#include <iostream>
#include "StringData.h"


int linear_search(std::vector<std::string> array, const std::string &string_to_find);
int binary_search(std::vector<std::string> array, const std::string &string_to_find);

int main(){
    std::vector<std::string> array = getStringData();
    long long time1 = systemTimeNanoseconds();
    int a1 = linear_search(array, "not_here");
    long long time2 = systemTimeNanoseconds() - time1;
    std::cout << "Index of not_here in linear: " << a1 << std::endl;
    std::cout << "Time: " << time2 << std::endl;
    time1 = systemTimeNanoseconds();
    int a2 = binary_search(array, "not_here");
    time2 = systemTimeNanoseconds() - time1;
    std::cout << "Index of not_here in binary: " << a2 << std::endl;
    std::cout << "Time: " << time2 << std::endl;
    time1 = systemTimeNanoseconds();
    int b1 = linear_search(array, "mzzzz");
    time2 = systemTimeNanoseconds() - time1;
    std::cout << "Index of mzzzz in linear: " << b1 << std::endl;
    std::cout << "Time: " << time2 << std::endl;
    time1 = systemTimeNanoseconds();
    int b2 = binary_search(array, "mzzzz");
    time2 = systemTimeNanoseconds() - time1;
    std::cout << "Index of mzzzz in binary: " << b2 << std::endl;
    std::cout << "Time: " << time2 << std::endl;
    time1 = systemTimeNanoseconds();
    int c1 = linear_search(array, "aaaaa");
    time2 = systemTimeNanoseconds() - time1;
    std::cout << "Index of aaaaa in linear: " << c1 << std::endl;
    std::cout << "Time: " << time2 << std::endl;
    time1 = systemTimeNanoseconds();
    int c2 = binary_search(array, "aaaaa");
    std::cout << "Time: " << time2 << std::endl;
    time2 = systemTimeNanoseconds() - time1;
    std::cout << "Index of aaaaa in binary: " << c2 << std::endl;
    std::cout << "Time: " << time2 << std::endl;
}

int linear_search(std::vector<std::string> array, const std::string &string_to_find){
    for (int i = 0; i < array.size(); i++) {
        if (array[i].compare(string_to_find) == 0) {
            return i;
        }
    }
    return -1;
}

int binary_search(std::vector<std::string> array, const std::string &string_to_find){
    int max = array.size();
    int min = 0;
    while (min <= max) {
        int guess = (min + max) / 2;
        int comparison = array[guess].compare(string_to_find);
        if (comparison == 0) {
            return guess;
        }
        else if (comparison < 0) {
            min = guess + 1;
        }
        else {
            max = guess - 1;
        }
    }
    return -1;
}
