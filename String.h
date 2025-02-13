#pragma once
#include <iostream>

class String
{
    int m_length{};
    int m_capacity{};
    char* m_data{};

    void new_capacity();
public:
    String();
    String(const char* str);
    String(const String& str);
    ~String() { delete[] m_data; }

    int length() { return m_length; }
    int capacity() { return m_capacity; }
    void push_back(char value);
    void pop_back();

    int erase(int index);
    void insert(int index, char value);
    char& at(int index);

    friend std::ostream& operator<<(std::ostream& out, const String& str);
    friend std::istream& operator>>(std::istream& in, String& str);
    char& operator[](int index) { return m_data[index]; }

    friend bool operator==(const String& str1, const String& str2);
    friend bool operator!=(const String& str1, const String& str2);
    friend bool operator>(const String& str1, const String& str2);
    friend bool operator<(const String& str1, const String& str2);
    friend bool operator>=(const String& str1, const String& str2);
    friend bool operator<=(const String& str1, const String& str2);
};