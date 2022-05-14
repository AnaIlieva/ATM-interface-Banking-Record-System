#pragma once
#ifndef CARD_H
#define	CARD_H

#include "MyString.h"

class Card {

private:
	MyString cardNumber;
	MyString PIN;

public:
	Card(MyString cardNumber, MyString PIN);

	MyString getCardNumber() const;
	MyString getPIN() const;

	void print() const;
	Card* clone() const;

	void setCardNumber(MyString cardNumber);
	void setPIN(MyString PIN);

};

#endif
