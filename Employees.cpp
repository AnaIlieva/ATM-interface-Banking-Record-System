#pragma warning(disable : 4996).
#include "Employees.h"

void Employees::copy(const Employees& other) {

	for (int i = 0; i < other.employees.size(); i++) {

		employees.push_back(other.employees[i]->clone());
	}
}

void Employees::free() {

	for (int i = 0; i < employees.size(); i++) {

		delete employees[i];
	}
	employees.clear();
}

Employees::Employees(const Employees& other) {

	copy(other);
}

Employees& Employees::operator=(const Employees& other) {

	if (this != &other) {

		free();
		copy(other);
	}
	return *this;
}

Employees::~Employees() {

	free();
}

void Employees::addEmployee(MyString egn, MyString firstName, MyString middleName, MyString lastName,
	MyString birthDate, MyString telephoneNumber, MyString address, MyString username, MyString password) {

	Employee* pointer = new Employee(egn, firstName, middleName, lastName, birthDate, telephoneNumber, address, username, password);
	employees.push_back(pointer);
}

void Employees::deleteEmployee(Employee& toBeDeleted) {

	int index = 0;
	for (int i = 0; i < employees.size(); i++) {

		if (employees[i] == &toBeDeleted) {

			index = i;
		}
	}

	employees.erase(employees.begin() + index);
}

Employee Employees::operator[](int pos) const {

	return *employees.operator[](pos);
}

void Employees::print() {

	for (int i = 0; i < employees.size(); i++) {

		employees[i]->print();
	}
}

int Employees::getCount() const {

	return employees.size();
}