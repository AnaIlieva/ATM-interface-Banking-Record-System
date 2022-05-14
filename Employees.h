#pragma once
#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include "Employee.h"

class Employees {

private:
	std::vector<Employee*> employees;

	void copy(const Employees& other);
	void free();

public:
	Employees() = default;
	Employees(const Employees& other);
	Employees& operator=(const Employees& other);
	~Employees();

	void addEmployee(MyString egn, MyString firstName, MyString middleName, MyString lastName,
		MyString birthDate, MyString telephoneNumber, MyString address, MyString username, MyString password);
	void deleteEmployee(Employee& toBeDeleted);

	Employee operator[](int pos) const;
	int getCount() const;

	void print();
};

#endif