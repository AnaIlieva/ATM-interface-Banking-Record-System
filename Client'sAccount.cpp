#pragma warning(disable : 4996).
#include "Client'sAccount.h"

ClientsAccount::ClientsAccount(MyString accountNumber, double balance) : accountNumber(accountNumber), balance(balance) {}

void ClientsAccount::copy(const ClientsAccount& other) {

	for (int i = 0; i < other.cards.size(); i++) {

		cards.push_back(other.cards[i]->clone());
	}
	accountNumber = other.accountNumber;
	balance = other.balance;
}

void ClientsAccount::free() {

	for (int i = 0; i < cards.size(); i++) {

		delete cards[i];
	}
	cards.clear();
}

ClientsAccount::ClientsAccount(const ClientsAccount& other) {

	copy(other);
}

ClientsAccount& ClientsAccount::operator=(const ClientsAccount& other) {

	if (this != &other) {

		free();
		copy(other);
	}
	return *this;
}

ClientsAccount::~ClientsAccount() {

	free();
}

void ClientsAccount::print() const {

	std::cout << accountNumber << " " << cards.size() << " " << balance << std::endl;
}

ClientsAccount* ClientsAccount::clone() const {

	ClientsAccount* copy = new ClientsAccount(*this);
	return copy;
}

MyString ClientsAccount::getAccountNumber() const {

	return accountNumber;
}

double ClientsAccount::getBalance() const{

	return balance;
}

int ClientsAccount::getCardsCount() const {

	return cards.size();
}

Card ClientsAccount::getCard(int pos) const {

	if (pos > cards.size()) {

		throw std::out_of_range("There's no card on this position!");
	}

	return *cards[pos];
}

MyString ClientsAccount::getCardNumber(int pos) const {

	return cards[pos]->getCardNumber();
}

MyString ClientsAccount::getPIN(int pos) const {

	return cards[pos]->getPIN();
}

void ClientsAccount::addCard(Card& toBeAdded) {

	Card* pointer = new Card(toBeAdded);
	cards.push_back(pointer);
}

void ClientsAccount::deleteCard(Card& toBeDeleted) {

	int index = 0;
	for (int i = 0; i < cards.size(); i++) {

		if (cards[i] == &toBeDeleted) {

			index = i;
		}
	}

	cards.erase(cards.begin() + index);
}

void ClientsAccount::addToBalance(double amount) {

	if (amount <= 0) {

		throw std::invalid_argument("Deposit amount should be a decimal positive number!");
	}
	balance += amount;
}

void ClientsAccount::substractFromBalance(double amount) {

	if (amount <= 0) {

		throw std::invalid_argument("Deposit amount should be a decimal positive number!");
	}

	if (amount > balance) {

		throw std::out_of_range("Not enough money in the account!");
	}

	balance -= amount;
}