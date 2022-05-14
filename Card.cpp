#pragma warning(disable : 4996).
#include "Card.h"

Card::Card(MyString cardNumber, MyString PIN) {

	setCardNumber(cardNumber);
	setPIN(PIN);
}

void Card::setCardNumber(MyString cardNumber) {

	for (int i = 0; i < cardNumber.getLen(); i++) {

		if (isdigit(cardNumber[i])) {

			this->cardNumber = cardNumber;
		}
	}
}

void Card::setPIN(MyString PIN) {

	for (int i = 0; i < PIN.getLen(); i++) {

		if (isdigit(PIN[i])) {

			this->PIN = PIN;
		}
	}
}

void Card::print() const {

	std::cout << cardNumber << " " << PIN << std::endl;
}

Card* Card::clone() const {

	Card* copy = new Card(*this);
	return copy;
}

MyString Card::getCardNumber() const {

	return cardNumber;
}

MyString Card::getPIN() const {

	return PIN;
}