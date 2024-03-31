#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class MyString
{
private:
    char *data; // pointer to char array data
    int length; // size

public:
    // defult constructcor
    MyString();

    // params constructor
    MyString(const char *str);

    // copy ctor
    MyString(const MyString &other);

    // detor
    ~MyString();

    int size() const;

    bool empty() const;

    // Return C-style string
    const char *c_str() const;

    char operator[](int index);

    // Assignment operator
    MyString &operator=(const MyString &other);

    // Concatenation (+=) operator
    MyString &operator+=(const MyString &other);

    // Append string
    void append(const MyString &other);

    // Find substring
    int find(const MyString &substr) const;

    // Erase substring
    void erase(size_t pos, size_t len);

    // overload << (insertion) ops
    friend std::ostream &operator<<(std::ostream &os, const MyString &str);
};

#endif