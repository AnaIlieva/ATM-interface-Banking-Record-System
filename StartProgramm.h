#pragma once
#ifndef START_PROGRAMM_H
#define	START_PROGRAMM_H

#include "Admin.h"
#include "Employee.h"
#include "Client.h"
#include "Employees.h"

void backOrExit(Admin& a, Employee& e, Client& c, const char* filenameClients, const char* filenameEmployees,
		const char* filenameAdmins, Employees& employees, Clients& clients);

void admin(MyString& egn, MyString& firstName, MyString& middleName, MyString& lastName, MyString& birthDate,
	MyString& telephoneNumber, MyString& address, MyString& username, MyString& password, Admin& a, const char* filenameAdmins, Employees& employees);

void employee(MyString& egn, MyString& firstName, MyString& middleName, MyString& lastName, MyString& birthDate, MyString& telephoneNumber,
	MyString& address, Employee& e, double amount, MyString accountNumber, MyString cardNumber, const char* filenameEmployees, Clients& clients);

void client(Client& c, double amount, const char* filenameClients, MyString& PIN);

void startProgramm(Admin& a, Employee& e, Client& c, const char* filenameClients, const char* filenameEmployees,
	const char* filenameAdmins, Employees& employees, Clients& clients);

#endif