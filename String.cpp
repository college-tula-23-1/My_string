#include "String.h"
String::String() : m_length{}, m_capacity{}, m_data{ nullptr }
{
}
String::String(const char* str)
{
    m_length = strlen(str);
    m_capacity = m_length + 1;
    m_data = new char[m_capacity];


    for (int i{}; i < m_length; ++i)
        m_data[i] = str[i];
    m_data[m_length] = '\0';
}
String::String(const String& str) : String(str.m_data)
{
}

void String::new_capacity()
{
    m_capacity = m_length + ((m_length) ? m_length / 2 : 10);

    char* new_data = new char[m_capacity];
    for (int i{}; i < m_length; ++i)
        new_data[i] = m_data[i];
    new_data[m_length] = '\0';

    delete[] m_data;
    m_data = new_data;
}

void String::push_back(char value)
{
    if (m_length + 1 >= m_capacity)
        new_capacity();

    m_data[m_length++] = value;
    m_data[m_length] = '\0';
}

void String::pop_back()
{
    --m_length;
    m_data[m_length] = '\0';

    if (m_capacity >= m_length * 2)
        new_capacity();
}

int String::erase(int index)
{

}

bool operator==(const String& str1, const String& str2)
{
    if (str1.m_length != str2.m_length)
        return false;
    if (str1.m_length == 0)
        return true;

    for (int i{}; i < str1.m_length; ++i)
        if (str1.m_data[i] != str2.m_data[i])
            return false;
    return true;
}
bool operator!=(const String& str1, const String& str2)
{
    return !(str1 == str2);
}


std::ostream& operator<<(std::ostream& out, const String& str)
{
    return out << str.m_data;
}
std::istream& operator>>(std::istream& in, String& str)
{
    return in;
}