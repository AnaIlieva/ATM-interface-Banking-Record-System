#pragma warning(disable : 4996).
#include "Client.h"

void Client::copy(const Client& other) {

	for (int i = 0; i < other.accounts.size(); i++) {

		accounts.push_back(other.accounts[i]->clone());
	}
}

void Client::free() {

	for (int i = 0; i < accounts.size(); i++) {

		delete accounts[i];
	}
	accounts.clear();
}

Client::Client(MyString egn, MyString firstName, MyString middleName, MyString lastName,
	MyString birthDate, MyString telephoneNumber, MyString address, int accountsCapacity)
	: Person(egn, firstName, middleName, lastName, birthDate, telephoneNumber, address) {

	//accounts = new ClientsAccount(accountsCapacity);
}

Client::Client(const Client& other) : Person(other) {

	copy(other);
}

Client& Client::operator=(const Client& other) {

	Person::operator=(other);

	if (this != &other) {

		free();
		copy(other);
	}
	return *this;
}

Client::~Client() {

	free();
}

void Client::print() const {

	Person::print();
	for (int i = 0; i < accounts.size(); i++) {

		accounts[i]->print();
	}
}

Client* Client::clone() const {

	Client* copy = new Client(*this);
	return copy;
}

ClientsAccount Client::operator[](int pos) const {

	return *accounts.operator[](pos);
}

void Client::addAccount(ClientsAccount& toBeAdded) {

	ClientsAccount* pointer = new ClientsAccount(toBeAdded);
	accounts.push_back(pointer);
}

void Client::deleteAccount(ClientsAccount& toBeDeleted) {

	int index = 0;
	for (int i = 0; i < accounts.size(); i++) {

		if (accounts[i] == &toBeDeleted) {

			index = i;
		}
	}

	accounts.erase(accounts.begin() + index);
}

int Client::getAccountsCount() const {

	return accounts.size();
}

MyString Client::getAccountNumber(int pos) const {

	if (pos > accounts.size()) {

		throw std::out_of_range("There's no card on this position!");
	}

	return accounts[pos]->getAccountNumber();
}

double Client::getBalance(int pos) const {

	if (pos > accounts.size()) {

		throw std::out_of_range("There's no card on this position!");
	}

	return accounts[pos]->getBalance();
}

MyString Client::getCardNumber(int pos) const {

	if (pos > accounts.size()) {

		throw std::out_of_range("There's no card on this position!");
	}

	return accounts[pos]->getCardNumber(pos);
}

MyString Client::getPIN(int pos) const {

	if (pos > accounts.size()) {

		throw std::out_of_range("There's no card on this position!");
	}

	return accounts[pos]->getPIN(pos);
}

int Client::getCardsCount(int pos) const {

	if (pos > accounts.size()) {

		throw std::out_of_range("There's no card on this position!");
	}

	return accounts[pos]->getCardsCount();
}

bool Client::login(const char* filename, MyString& PIN) {

	std::cout << "Please, enter your card number!" << std::endl;

	MyString cardNumber;
	std::cin >> cardNumber;

	for (int i = 0; i < accounts.size(); i++) {
		
		if (accounts[i]->getCardNumber(i) == cardNumber) {

			std::cout << "Please, enter your PIN!" << std::endl;

			std::cin >> PIN;

			if (accounts[i]->getPIN(i) == PIN) {

				std::cout << "Success! :)" << std::endl;
				return true;
			}
			else {

				while (accounts[i]->getPIN(i) != PIN) {

					std::cout << "Please, enter your PIN!" << std::endl;
					std::cin >> PIN;
				}
				std::cout << "Success! :)" << std::endl;
				return true;
			}
		}
		else {

			std::cout << "There's no such user!" << std::endl;
			return false;
		}
	}
}

void Client::deposit(double amount, MyString& PIN) {

	std::cout << "Please, enter the amount you want to deposit: ";
	std::cin >> amount;

	for (int i = 0; i < accounts.size(); i++) {

		if (accounts[i]->getPIN(i) == PIN) {

			accounts[i]->addToBalance(amount);
		}
	}
}

void Client::withdraw(double amount, MyString& PIN) {

	std::cout << "Please, enter the amount you want to withdraw: ";
	std::cin >> amount;

	for (int i = 0; i < accounts.size(); i++) {

		if (accounts[i]->getPIN(i) == PIN) {

			accounts[i]->substractFromBalance(amount);
		}
	}
}

void Client::checkBalance(MyString& PIN) {

	for (int i = 0; i < accounts.size(); i++) {

		if (accounts[i]->getPIN(i) == PIN) {

			std::cout << "Balance: " << accounts[i]->getBalance() << std::endl;
		}
	}
}
