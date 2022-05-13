#pragma once
#ifndef ADMIN_H
#define ADMIN_H

#include "Employees.h"

class Admin {

private:
	MyString adminUsername;
	MyString adminPassword;

	void input(const MyString& message, MyString& toInput);

public:
	Admin(MyString& username, MyString& password);

	void addAdminToFile(MyString& username, MyString& password);

	bool login(const char* filename);

	void addEmployee(Employees& employees, MyString& egn, MyString& firstName, MyString& middleName, MyString& lastName,
		MyString& birthDate, MyString& telephoneNumber, MyString& address, MyString& username, MyString& password);
	void deleteEmployee(Employees& employees, MyString& egn);
};

#endif
