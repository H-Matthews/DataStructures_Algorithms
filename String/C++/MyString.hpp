#include <string>

/*
Creating a string class 
This requires implementing the Rule of Three which is stated as the following:
    If you attempt to manage your own memory, you will most likely need the following functions
        1. Destructor
        2. Copy Constructor
        3. Overloaded assignment operator
    ** I am using dynamically allocated arrays so I need a destructor to properly manage the resource once my 
       object goes out of scope.
*/

class MyString
{
    private:
        char* _str;
        int _len;

    public:
        // Constructors
        MyString();
        MyString(const char* s1);
        MyString(const MyString& obj);

        // Destructors
        ~MyString();

        // Overloaded operators
        MyString operator+(MyString const& obj);
        MyString& operator=(const MyString& obj);

        int length();
        char* buffer();
};