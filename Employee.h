#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Clients.h"
#include <cstdlib>
#include <ctime>

class Employee : public Person {

protected:
	MyString employeeUsername;
	MyString employeePassword;

	void input(const MyString message, MyString& toInput);
	MyString toString(int n);

public:
	Employee(MyString egn, MyString firstName, MyString middleName, MyString lastName, 
		MyString birthDate, MyString telephoneNumber, MyString address, MyString username, MyString password);

	void print() const override;
	Employee* clone() const;

	MyString getEmployeeUsername() const;
	MyString getEmployeePassword() const;

	bool login(const char* filename);

	void addClient(Clients& clients, MyString egn, MyString firstName, MyString middleName, MyString lastName,
		MyString birthDate, MyString telephoneNumber, MyString address);
	void deleteClient(Clients& clients, MyString egn);

	void openAnAccount(MyString egn, double amount, Clients& clients);
	void addCardToAccount(MyString egn, MyString accountNumber, Clients& clients);

	void deleteAnAccount(MyString egn, MyString accountNumber, Clients& clients);
	void deleteCardFromAccount(MyString egn, MyString accountNumber, MyString cardNumber, Clients& clients);

	void printBankReport(Clients& clients);
	void printIndividualReport(MyString egn, Clients& clients);
};

#endif
