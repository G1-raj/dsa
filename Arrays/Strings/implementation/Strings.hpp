#ifndef Strings_HPP
#define Strings_HPP


class String {
    private:
        char* char_array;
        int length;

    public:

        String() : char_array(nullptr), length(0) {}
        String(const char* input);
        String(const String& other);
        String& operator=(const String& other);
        ~String();


        void print();
        String slice(int from , int to);
        std::vector<String> split(char split_symbol);
};





#endif