#pragma warning(disable : 4996).
#include "MyString.h"

void MyString::copyString(char* destination, const char* source) {

	int length = strlen(source);
	for (int i = 0; i < length; i++)
	{
		destination[i] = source[i];
	}
	destination[length] = '\0';
}

void MyString::copy(const MyString& other) {

	string = new char[strlen(other.string) + 1];
	copyString(string, other.string);
}

void MyString::free() {

	delete[] string;
}

void MyString::resize() {

	char* tmp = new char[strlen(string) * 2];
	copyString(tmp, this->string);
	delete[] this->string;
	this->string = tmp;
}

MyString::MyString() : string(nullptr) {

	string = new char[1];
	string[0] = '\0';
}

MyString::MyString(const char* string) {

	if (string == nullptr) {
		this->string = new char[1];
		this->string[0] = '\0';
	}
	else {

		this->string = new char[strlen(string) + 1];
		copyString(this->string, string);
	}
}

MyString::MyString(const MyString& other) {

	copy(other);
}

MyString& MyString::operator=(const MyString& other) {

	if (this != &other) {

		free();
		copy(other);
	}
	return *this;
}

MyString::MyString(MyString&& other) noexcept {

	string = other.string;
	other.string = nullptr;
}

MyString& MyString::operator=(MyString&& other) noexcept {

	free();

	string = std::move(other.string);
	other.string = nullptr;

	return *this;
}

MyString::~MyString() {

	free();
}

MyString MyString::getString() const {

	return string;
}

int MyString::getLen() const {

	return strlen(string);
}

MyString MyString::findLastNChars(int n, MyString lastNChars) {

	for (int i = getLen() - n, j = 0; i < getLen(), j < n; i++, j++) {

		lastNChars[j] = string[i];
	}

	lastNChars[n] = '\0';
	return lastNChars;
}

MyString& MyString::operator=(char* other) {

	string = new char[strlen(other) + 1];
	copyString(string, other);
	return *this; 
}

bool MyString::operator==(const MyString& other) {

	if (strlen(string) != strlen(other.string)) {

		return false;
	}

	for (int i = 0; i < strlen(string); i++) {

		return string[i] == other.string[i];
	}
}

bool MyString::operator!=(const MyString& other) {

	return !operator== (other);
}

MyString MyString::operator+(const MyString& other) {

	int len = strlen(string) + strlen(other.string) + 1;

	char* buff = new char[len];
	strcpy(buff, string);
	strcat(buff, other.string);

	MyString tmp(buff);
	delete[] buff;

	return tmp;
}

std::ostream& operator<<(std::ostream& os, const MyString& object) {

	os << object.string;
	return os;
}

std::istream& operator>>(std::istream& is, MyString& other) {

	int charsCount = 0;

	MyString newString("new string");
	other = newString;

	char currentChar = is.get();

	while (currentChar != '\n') {

		if (charsCount >= other.getLen()) {

			other.resize();
		}
		other.string[charsCount++] = currentChar;
		currentChar = is.get();
	}
	other.string[charsCount] = '\0';
	return is;
}

const char& MyString::operator[](const int position) const {

	return string[position];
}

char& MyString::operator[](const int position) {

	return string[position];
}