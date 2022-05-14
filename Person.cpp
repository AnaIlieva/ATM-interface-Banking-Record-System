#pragma warning(disable : 4996).
#include "Person.h"

Person::Person(MyString egn, MyString firstName, MyString middleName, MyString lastName, MyString birthDate, MyString telephoneNumber, MyString address)
	: birthDate(birthDate), address(address) {

	setEgn(egn);
	setFirstName(firstName);
	setMiddleName(middleName);
	setLastName(lastName);
	setTelephoneNumber(telephoneNumber);
}

void Person::print() const {

	std::cout << egn << " " << firstName << " " << middleName << " " << lastName << " " << birthDate << " " << telephoneNumber << " " << address << " ";
}

void Person::setEgn(MyString egn) {

	for (int i = 0; i < egn.getLen(); i++) {

		if (isdigit(egn[i])) {

			this->egn = egn;
		}
	}
}

void Person::setFirstName(MyString firstName) {

	for (int i = 0; i < firstName.getLen(); i++) {

		if (isalpha(firstName[i])) {

			this->firstName = firstName;
		}
	}
}

void Person::setMiddleName(MyString middleName) {

	for (int i = 0; i < middleName.getLen(); i++) {

		if (isalpha(middleName[i])) {

			this->middleName = middleName;
		}
	}
}

void Person::setLastName(MyString lastName) {

	for (int i = 0; i < lastName.getLen(); i++) {

		if (isalpha(lastName[i])) {

			this->lastName = lastName;
		}
	}
}

void Person::setTelephoneNumber(MyString telephoneNumber) {

	for (int i = 0; i < telephoneNumber.getLen(); i++) {

		if (isdigit(telephoneNumber[i])) {

			this->telephoneNumber = telephoneNumber;
		}
	}
}

MyString Person::getEgn() const {

	return egn;
}

MyString Person::getFirstName() const {

	return firstName;
}

MyString Person::getMiddleName() const {

	return middleName;
}

MyString Person::getLastName() const {

	return lastName;
}

MyString Person::getBirthDate() const {

	return birthDate;
}

MyString Person::getTelephoneNumber() const {

	return telephoneNumber;
}

MyString Person::getAddress() const {

	return address;
}