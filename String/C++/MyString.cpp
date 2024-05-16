#include "MyString.hpp"
#include "string.h"

MyString::MyString()
{
    _len = 0;
    _str = NULL;
}

MyString::MyString(const char* s1)
{
    this->_len = strlen(s1);
    this->_str = new char[_len + 1]; // +1 for Null Terminator

    std::copy(s1, s1 + this->_len, this->_str ); // Copy s1 into this instance
    this->_str[_len + 1] = '\0';
}

MyString::MyString(const MyString& obj)
{
    this->_len = obj._len;
    this->_str = new char[_len + 1]; // +1 for Null Terminator

    std::copy(obj._str, &obj._str[obj._len], this->_str); // Copy obj into this
    this->_str[obj._len + 1] = '\0';
}

MyString::~MyString()
{
    delete[] _str;
}

MyString MyString::operator+(const MyString& obj)
{
    MyString _s1;

    // Determine new length and Memory
    _s1._len = this->_len + obj._len;
    _s1._str = new char[_s1._len + 1];

    // Copy Contents of this* to _s1
    std::copy(this->_str, &this->_str[this->_len], _s1._str );

    // Copy contents of obj* to _s1
    std::copy(obj._str, &obj._str[obj._len], _s1._str + this->_len );

    // Append null terminator
    _s1._str[_s1._len + 1] = '\0';

    return _s1;
}

MyString& MyString::operator=(const MyString& obj)
{
    // Delete memory blocka nd re-allocate
    if(this->_str != NULL)
        delete[] this->_str;


    this->_len = obj._len;
    this->_str = new char[this->_len + 1];

    std::copy(obj._str, &obj._str[obj._len], this->_str );
    this->_str[obj._len + 1] = '\0';

    return *this;
}

int MyString::length()
{
    return _len;
}

char* MyString::buffer()
{
    return _str;
}