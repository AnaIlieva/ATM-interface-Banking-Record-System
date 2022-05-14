#pragma once
#ifndef CLIENTS_ACCOUNT_H
#define	CLIENTS_ACCOUNT_H

#include "Card.h"
#include <vector>

class ClientsAccount {

private:
	MyString accountNumber;
	std::vector<Card*> cards;
	double balance;

	void copy(const ClientsAccount& other);
	void free();

public:
	ClientsAccount(MyString accountNumber, double balance);
	ClientsAccount(const ClientsAccount& other);
	ClientsAccount& operator=(const ClientsAccount& other);
	~ClientsAccount();

	void print() const;
	ClientsAccount* clone() const;

	MyString getAccountNumber() const;
	double getBalance() const;
	int getCardsCount() const;
	Card getCard(int pos) const;
	MyString getCardNumber(int pos) const;
	MyString getPIN(int pos) const;

	void addCard(Card& toBeAdded);
	void deleteCard(Card& toBeDeleted);
	void addToBalance(double amount);
	void substractFromBalance(double amount);

};

#endif