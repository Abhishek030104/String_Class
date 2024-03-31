#include "MyString.h"
#include <cstring> // to use strcpy

//  defination of all the function decleare in header\

// defult ctor
MyString::MyString()
{
    data = new char[1];
    length = 0;
    data[1] = '\0';
}

// params ctor
MyString::MyString(const char *str)
{
    data = new char[strlen(str) + 1];
    length = strlen(str);
    strcpy(data, str);
}

// copy ctor
MyString::MyString(const MyString &other)
{
    data = new char[other.length + 1];
    length = other.length;
    strcpy(data, other.data);
}

// destructor
MyString::~MyString()
{
    delete data;
}

int MyString::size() const
{
    return length;
}

bool MyString::empty() const
{
    return length == 0;
}

const char *MyString::c_str() const
{
    return data;
}

// Assignment operator
MyString &MyString::operator=(const MyString &other)
{
    if (this == &other)
    {
        return *this; // Return *this to deal with self-assignment
    }

    // Free existing resources
    delete[] data;

    // Copy data from other string
    data = new char[other.length + 1];
    length = other.length;
    strcpy(data, other.data);

    return *this;
}

// Concatenation (+=) operator
MyString &MyString::operator+=(const MyString &other)
{
    char *newData = new char[length + other.length + 1];
    strcpy(newData, data);
    strcat(newData, other.data);

    // Free old memory and assign new data
    delete[] data;
    data = newData;
    length += other.length;

    return *this;
}

// overload []
char MyString::operator[](int index)
{
    if (index >= length || index < 0)
    {
        return '\0';
    }
    return data[index];
}
// overload insertion << operator
std::ostream &operator<<(std::ostream &os, const MyString &str)
{
    os << str.c_str();
}

// Append string
void MyString::append(const MyString &other)
{
    *this += other;
}

// Find substring
int MyString::find(const MyString &substr) const
{
    if (substr.length > length)
        return -1;

    for (size_t i = 0; i <= length - substr.length; ++i)
    {
        size_t j;
        for (j = 0; j < substr.length; ++j)
        {
            if (data[i + j] != substr.data[j])
            {
                break;
            }
        }

        // If the inner loop ran fully, that means we found our string.
        if (j == substr.length)
        {
            return i;
        }
    }
    return -1;
}

// Erase substring
void MyString::erase(size_t pos, size_t len)
{
    if (pos >= length)
    {
        throw std::out_of_range("Position out of range");
    }

    if (len == 0)
    {
        return;
    }

    if (len > length - pos)
    {
        len = length - pos; // Erase till the end if len exceeds the string length from pos
    }

    // Calculate new length
    size_t newLength = length - len;

    // Create new data array
    char *newData = new char[newLength + 1];

    // Copy characters before 'pos'
    strncpy(newData, data, pos);

    // Copy characters after 'pos + len'
    strcpy(newData + pos, data + pos + len);

    // Null-terminate the new string
    newData[newLength] = '\0';

    // Delete old data and replace with new data
    delete[] data;
    data = newData;

    // Update length
    length = newLength;
}