#pragma once
#ifndef PERSON_H
#define PERSON_H

#include "MyString.h"

#include <ctype.h>

class Person {

protected:
	MyString egn;
	MyString firstName;
	MyString middleName;
	MyString lastName;
	MyString birthDate;
	MyString telephoneNumber;
	MyString address;

public:
	Person(MyString egn, MyString firstName, MyString middleName, MyString lastName, MyString birthDate, MyString telephoneNumber, MyString address);
	
	virtual void print() const;

	void setEgn(MyString egn);
	void setFirstName(MyString firstName);
	void setMiddleName(MyString middleName);
	void setLastName(MyString lastName);
	void setTelephoneNumber(MyString telephoneNumber);

	MyString getEgn() const;
	MyString getFirstName() const;
	MyString getMiddleName() const;
	MyString getLastName() const;
	MyString getBirthDate() const;
	MyString getTelephoneNumber() const;
	MyString getAddress() const;
};

#endif