#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include "Person.h"
#include "Client'sAccount.h"
#include <stdexcept>

class Client : public Person {

private:
	std::vector<ClientsAccount*> accounts;

	void copy(const Client& other);
	void free();

public:
	Client(MyString egn, MyString firstName, MyString middleName, MyString lastName, 
		MyString birthDate, MyString telephoneNumber, MyString address, int accountsCapacity = 1);
	Client(const Client& other);
	Client& operator=(const Client& other);
	~Client();

	void print() const override;
	Client* clone() const;

	ClientsAccount operator[](int pos) const;

	void addAccount(ClientsAccount& toBeAdded);
	void deleteAccount(ClientsAccount& toBeDeleted);

	int getAccountsCount() const;
	MyString getAccountNumber(int pos) const;
	double getBalance(int pos) const;
	MyString getCardNumber(int pos) const;
	MyString getPIN(int pos) const;
	int getCardsCount(int pos) const;

	bool login(const char* filename, MyString& PIN);
	void deposit(double amount, MyString& PIN);
	void withdraw(double amount, MyString& PIN);
	void checkBalance(MyString& PIN);
};

#endif

