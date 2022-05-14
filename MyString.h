#ifndef MYSTRING_H
#define	MYSTRING_H

#include <iostream>
#include <cstring>
#include <fstream>

class MyString {

private:
	char* string;

    void copyString(char* destination, const char* source);
    void copy(const MyString& other);
    void free(); 
    void resize();

public:
    MyString();
    MyString(const char* string);
    MyString(const MyString& other);
    MyString& operator=(const MyString& other);
    MyString(MyString&& other) noexcept;
    MyString& operator=(MyString&& other) noexcept;
    ~MyString();

    MyString getString() const;
    int getLen() const;

    MyString findLastNChars(int n, MyString lastNChars);

    MyString& operator=(char* other);
    bool operator==(const MyString& other);
    bool operator!=(const MyString& other);
    MyString operator+(const MyString& other);

    friend std::ostream& operator<<(std::ostream& os, const MyString& object);
    friend std::istream& operator>>(std::istream& is, MyString& word);

    const char& operator[](const int position) const;
    char& operator[](const int position);
};

#endif