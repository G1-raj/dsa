#include <iostream>
#include <vector>
#include "Strings.hpp"

using namespace std;

String::String(const char* input) {

    size_t size = 0;
    length = 0;
    
    while(input[size] != '\0') {
        size++;
    }

    length = size;

    char_array = new char[size + 1];

    for(size_t i = 0; i < size; i++) {
        char_array[i] = input[i];
    }

    char_array[size] = '\0';

}

String::String(const String& other) {
    length = other.length;
    char_array = new char[length + 1];

    for (int i = 0; i < length; i++) {
        char_array[i] = other.char_array[i];
    }
    char_array[length] = '\0';
}

String& String::operator=(const String& other) {
    if(this == &other) {
        return *this;
    }

    delete[] char_array;

    length = other.length;
    char_array = new char[length + 1];
    for (int i = 0; i < length; i++) {
        char_array[i] = other.char_array[i];
    }

    char_array[length] = '\0';

    return *this;
}

void String::print() {

    for(int i = 0; i < length; i++) {
        cout << char_array[i];
    }

}

String String::slice(int from, int to) {

    size_t sliced_size = to - from;
    char* sliced_string = new char[sliced_size + 1];
    
    for(size_t i = 0; i < sliced_size; i++) {
        sliced_string[i] = char_array[from + i];
    }

    sliced_string[sliced_size] = '\0';

    String sliced_result(sliced_string);

    delete[] sliced_string;

    return sliced_result;
}

vector<String> String::split(char split_symbol) {
    vector<String> result;

    int start = 0;

    for(int i = 0; i <= length; i++) {
        if(char_array[i] == split_symbol || char_array[i] == '\0') {
            String part = slice(start, i);
            result.push_back(part);
            start = i + 1;
        }
    }

    return result;
}

String::~String() {
    delete[] char_array;
}


