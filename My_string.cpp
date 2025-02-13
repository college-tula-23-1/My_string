#include <iostream> 

class String
{
    int length{};
    int capacity{};
    char* data{};

public:
    String();
    String(const char* str);
    String(const String& str);
    ~String() { delete[] data; }

    friend std::ostream& operator<<(std::ostream& out, const String& str);
    friend std::istream& operator>>(std::istream& in, String& str);
    char& operator[](int index) { return data[index]; }

    friend bool operator==(const String& str1, const String& str2);
};

bool operator==(const String& str1, const String& str2)
{
    if (str1.length != str2.length)
        return false;
    if (str1.length == 0)
        return true;

    for (int i{}; i < str1.length; ++i)
        if (str1.data[i] != str2.data[i])
            return false;
    return true;
}

String::String() : length{}, capacity{}, data{ nullptr }
{
}
String::String(const char* str)
{
    length = strlen(str);
    capacity = length;
    data = new char[capacity + 1];

    for (int i{}; i < length; ++i)
        data[i] = str[i];
    data[length] = '\0';
}
String::String(const String& str) : String(str.data)
{
}
std::ostream& operator<<(std::ostream& out, const String& str)
{
    return out << str.data;
}
std::istream& operator>>(std::istream& in, String& str)
{
    return in;
}

int main()
{
    
}