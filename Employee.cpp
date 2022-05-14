#pragma warning(disable : 4996).
#include "Employee.h"

void Employee::input(const MyString message, MyString& toInput) {

	std::cout << message;
	std::cin >> toInput;
}

MyString Employee::toString(int n) { // the idea is taken from internet

	int m = n;
	char s[100];
	char ss[100];

	int i = 0, j = 0;
	if (n < 0) {

		m = 0 - m;
		j = 1;
		ss[0] = '-';
	}

	while (m > 0) {

		s[i++] = m % 10 + '0';
		m /= 10;
	}

	s[i] = '\0';
	i = i - 1;
	while (i >= 0) {

		ss[j++] = s[i--];
	}

	ss[j] = '\0';
	return ss;
}

Employee::Employee(MyString egn, MyString firstName, MyString middleName, MyString lastName, 
	MyString birthDate, MyString telephoneNumber, MyString address, MyString username, MyString password) 
	: Person(egn, firstName, middleName, lastName, birthDate, telephoneNumber, address), employeeUsername(username), employeePassword(password) {}

void Employee::print() const {

	Person::print();
	std::cout << employeeUsername << " " << employeePassword << std::endl;
}

Employee* Employee::clone() const {

	Employee* copy = new Employee(*this);
	return copy;
}

MyString Employee::getEmployeeUsername() const {

	return employeeUsername;
}

MyString Employee::getEmployeePassword() const {

	return employeePassword;
}

bool Employee::login(const char* filename) {

	std::cout << "Please, enter your username!" << std::endl;

	std::cin >> employeeUsername;

	std::ifstream i_file;
	i_file.open(filename);

	if (!i_file.is_open()) {

		std::cout << "File could not be opened!" << std::endl;
	}

	const int BUFF_SIZE = 1024;
	while (!i_file.eof())
	{
		char word[BUFF_SIZE];
		i_file.getline(word, BUFF_SIZE, ' ');

		if (employeeUsername == word) {

			std::cout << "Please, enter your password!" << std::endl;
			std::cin >> employeePassword;

			i_file.getline(word, BUFF_SIZE, ' ');
			if (employeePassword == word) {

				std::cout << "Success! :)" << std::endl;
				return true;
			}
			else {

				while (employeePassword != word) {

					std::cout << "Wrong password! Try again! :)" << std::endl;
					std::cin >> employeePassword;
				}
				std::cout << "Success! :)" << std::endl;
				return true;
			}
		}
		else {

			continue;
		}
	}
	i_file.close();

	std::cout << "There's no such user!" << std::endl;
	return false;
}

void Employee::addClient(Clients& clients, MyString egn, MyString firstName, MyString middleName, MyString lastName,
	MyString birthDate, MyString telephoneNumber, MyString address) {

	std::ofstream o_file;
	o_file.open("Clients.txt", std::ios::trunc);

	if (!o_file.is_open()) {

		std::cout << "File could not be opened!" << std::endl;
	}

	std::cout << "To create a Client - account please enter the following: " << std::endl;

	input("EGN: ", egn);

	std::ifstream i_file;
	i_file.open("Clients.txt");

	if (!i_file.is_open()) {

		std::cout << "File could not be opened!" << std::endl;
	}

	const int BUFF_SIZE = 1024;
	while (!i_file.eof())
	{
		char word[BUFF_SIZE];
		i_file.getline(word, BUFF_SIZE, ' ');

		if (egn == word) {

			std::cout << "Client with this EGN exists!" << std::endl;
			return;
		}
		else {

			input("First name: ", firstName);
			input("Middle name: ", middleName);
			input("Last name: ", lastName);
			input("Birth date: ", birthDate);
			input("Telephone number: ", telephoneNumber);
			input("Address: ", address);

			Client c(egn, firstName, middleName, lastName, birthDate, telephoneNumber, address);
			clients.addClient(c);

			o_file << egn << " " << firstName << " " <<
				middleName << " " << lastName << " " << birthDate << " " << telephoneNumber << " " << address <<  " " << std::endl;

			std::cout << "You have successfully added a Client - account!" << std::endl;

			o_file.close();
			i_file.close();
			return;
		}
	}
}

void Employee::deleteClient(Clients& clients, MyString egn) {

	input("Enter the EGN of the client: ", egn);

	std::ifstream i_file;
	i_file.open("Clients.txt");

	if (!i_file.is_open()) {

		std::cout << "File could not be opened!" << std::endl;
	}

	const int BUFF_SIZE = 1024;
	while (!i_file.eof())
	{
		char word[BUFF_SIZE];
		i_file.getline(word, BUFF_SIZE, ' ');

		if (egn != word) {

			do {

				i_file.getline(word, BUFF_SIZE, ' ');

			} while (i_file.get() != '\n');
			continue;
		}
		else {

			for (int i = 0; i < clients.getCount(); i++) {

				if (clients[i].getEgn() == egn) {

					Client toBeDeleted = clients[i];
					clients.deleteClient(toBeDeleted);
					std::cout << "Successfully deleted Client." << std::endl;
					i_file.close();
					return;
				}
			}
		}
	}
	std::cout << "There's no client with this EGN!" << std::endl;
	i_file.close();
}

void Employee::openAnAccount(MyString egn, double amount, Clients& clients) {

	std::cout << "Please enter the EGN of the client: " << std::endl;
	std::cin >> egn;

	std::ifstream i_file;
	i_file.open("Clients.txt");

	if (!i_file.is_open()) {

		std::cout << "File could not be opened!" << std::endl;
	}

	const int BUFF_SIZE = 1024;
	while (!i_file.eof())
	{
		char word[BUFF_SIZE];

		i_file.getline(word, BUFF_SIZE, ' ');

		if (egn != word) {

			do {

				i_file.getline(word, BUFF_SIZE, ' ');

			} while (i_file.get() != '\n');
			continue;
		}
		else {

			std::cout << "Please enter the amount you want to deposit: " << std::endl;
			std::cin >> amount;

			for (int i = 0; i < clients.getCount(); i++) {

				if (clients[i].getEgn() == egn) {

					char last4Digits[5];
					MyString lastFourDigitsOfEgn = clients[i].getEgn().findLastNChars(4, last4Digits);
					MyString beg = "00MYBANK";
					MyString accountNumber = beg + lastFourDigitsOfEgn + toString(clients[i].getAccountsCount());

					ClientsAccount account(accountNumber, amount);
					clients[i].addAccount(account);

					std::ofstream o_file;
					o_file.open("Client'sAccounts.txt", std::ios::app);

					if (!o_file.is_open()) {

						std::cout << "File could not be opened!" << std::endl;
					}

					o_file << egn << " " << accountNumber << " " << amount << " " << account.getCardsCount() << std::endl;

					std::cout << "You have successfully opened new account!" << std::endl;

					o_file.close();
					i_file.close();
					return;
				}
			}
		}
	}
	i_file.close();
	std::cout << "There's no such client with this EGN!" << std::endl;
}

void Employee::addCardToAccount(MyString egn, MyString accountNumber, Clients& clients) {

	std::cout << "Please enter the EGN of the client: " << std::endl;
	std::cin >> egn;

	std::ifstream i_file;
	i_file.open("Clients.txt");

	if (!i_file.is_open()) {

		std::cout << "File could not be opened!" << std::endl;
	}

	const int BUFF_SIZE = 1024;
	while (!i_file.eof())
	{
		char word[BUFF_SIZE];
		i_file.getline(word, BUFF_SIZE, ' ');

		if (egn != word) {

			do {

				i_file.getline(word, BUFF_SIZE, ' ');

			} while (i_file.get() != '\n');
			continue;
		}
		else {

			std::cout << "Enter the number of the account: " << std::endl;
			std::cin >> accountNumber;

			for (int i = 0; i < clients.getCount(); i++) {

				if (clients[i].getEgn() == egn) {

					for (int j = 0; j < clients[i].getAccountsCount(); j++) {

						if (clients[i][j].getAccountNumber() == accountNumber) {

							char last4Digits[5];
							MyString beg = "00";
							MyString lastFourDigitsOfEgn = egn.findLastNChars(4, last4Digits);
							MyString cardNumber = beg + lastFourDigitsOfEgn + toString(clients[i][j].getCardsCount());

							srand(time(0));
							MyString firstRandomNum = toString(rand() % 10);
							MyString secondRandomNum = toString(rand() % 10);
							MyString thirdRandomNum = toString(rand() % 10);
							MyString fourthRandomNum = toString(rand() % 10);

							MyString PIN = firstRandomNum + secondRandomNum + thirdRandomNum + fourthRandomNum;

							Card card(cardNumber, PIN);
							clients[i][j].addCard(card);
						}
						else {

							std::cout << "There's no such Client - account!" << std::endl;
							return;
						}
					}
				}
			}
		}
	}
	i_file.close();
	std::cout << "There's no such client with this EGN!" << std::endl;
}

void Employee::deleteAnAccount(MyString egn, MyString accountNumber, Clients& clients) {

	std::cout << "Please enter the EGN of the client: " << std::endl;
	std::cin >> egn;

	std::ifstream i_file;
	i_file.open("Clients.txt");

	if (!i_file.is_open()) {

		std::cout << "File could not be opened!" << std::endl;
	}

	const int BUFF_SIZE = 1024;
	while (!i_file.eof())
	{
		char word[BUFF_SIZE];
		i_file.getline(word, BUFF_SIZE, ' ');

		if (egn != word) {

			do {

				i_file.getline(word, BUFF_SIZE, ' ');

			} while (i_file.get() != '\n');
			continue;
		}
		else {

			std::cout << "Enter the number of the account: " << std::endl;
			std::cin >> accountNumber;

			for (int i = 0; i < clients.getCount(); i++) {

				if (clients[i].getEgn() == egn) {

					for (int j = 0; j < clients[i].getAccountsCount(); j++) {

						if (clients[i][j].getAccountNumber() == accountNumber) {

							ClientsAccount toBeDeleted = clients[i][j];
							clients[i].deleteAccount(toBeDeleted);
							std::cout << "Successfully deleted account." << std::endl;
						}
						else {

							std::cout << "There's no such Client - account!" << std::endl;
							return;
						}
					}
				}
			}
		}
	}
	i_file.close();
	std::cout << "There's no such client with this EGN!" << std::endl;
}

void Employee::deleteCardFromAccount(MyString egn, MyString accountNumber, MyString cardNumber, Clients& clients) {

	std::cout << "Please enter the EGN of the client: ";
	std::cin >> egn;

	std::ifstream i_file;
	i_file.open("Clients.txt");

	if (!i_file.is_open()) {

		std::cout << "File could not be opened!" << std::endl;
	}

	const int BUFF_SIZE = 1024;
	while (!i_file.eof())
	{
		char word[BUFF_SIZE];
		i_file.getline(word, BUFF_SIZE, ' ');

		if (egn != word) {

			do {

				i_file.getline(word, BUFF_SIZE, ' ');

			} while (i_file.get() != '\n');
			continue;
		}
		else {

			std::cout << "Enter the number of the account: " << std::endl;
			std::cin >> accountNumber;

			for (int i = 0; i < clients.getCount(); i++) {

				if (clients[i].getEgn() == egn) {

					for (int j = 0; j < clients[i].getAccountsCount(); j++) {

						if (clients[i][j].getAccountNumber() == accountNumber) {

							std::cout << "Enter the number of the card: " << std::endl;
							std::cin >> cardNumber;

							if (clients[i][j].getCardNumber(j) == cardNumber) {

								Card toBeDeleted = clients[i][j].getCard(j);
								clients[i][j].deleteCard(toBeDeleted);
								std::cout << "Successfully deleted card." << std::endl;
							}
							else {

								std::cout << "There's no such card!" << std::endl;
								return;
							}
						}
						else {

							std::cout << "There's no such Client - account!" << std::endl;
							return;
						}
					}
				}
			}
		}
	}
	i_file.close();
	std::cout << "There's no such client with this EGN!" << std::endl;
}

void Employee::printBankReport(Clients& clients) {

	for (int i = 0; i < clients.getCount(); i++) {

		std::cout << clients[i].getEgn() << " " << clients[i].getAccountsCount() << " " << clients[i].getCardsCount(i) << std::endl;
	}
}

void Employee::printIndividualReport(MyString egn, Clients& clients) {

	std::cout << "Enter the EGN of the client: ";
	std::cin >> egn;

	std::ifstream i_file;
	i_file.open("Clients.txt");

	if (!i_file.is_open()) {

		std::cout << "File could not be opened!" << std::endl;
	}

	const int BUFF_SIZE = 1024;
	while (!i_file.eof())
	{
		char word[BUFF_SIZE];
		i_file.getline(word, BUFF_SIZE, ' ');

		if (egn != word) {

			do {

				i_file.getline(word, BUFF_SIZE, ' ');

			} while (i_file.get() != '\n');
			continue;
		}
		else {

			for (int i = 0; i < clients.getCount(); i++) {

				if (clients[i].getEgn() == egn) {

					std::cout << "-------Client-------" << std::endl;
					std::cout << "Egn: " << clients[i].getEgn() << std::endl;
					std::cout << "First name: " << clients[i].getFirstName() << std::endl;
					std::cout << "Middle name: " << clients[i].getMiddleName() << std::endl;
					std::cout << "Last name: " << clients[i].getLastName() << std::endl;
					std::cout << "Birth date: " << clients[i].getBirthDate() << std::endl;
					std::cout << "Telephone number: " << clients[i].getTelephoneNumber() << std::endl;
					std::cout << "Address: " << clients[i].getAddress() << std::endl;
					std::cout << "Number of accounts: " << clients[i].getAccountsCount() << std::endl;

					if (clients[i].getAccountsCount() == 0) {

						std::cout << "Client has no accounts." << std::endl;
					}
					else {

						for (int j = 0; j < clients[i].getAccountsCount(); j++) {

							std::cout << "-----Account" << j + 1 << "-----" << std::endl;
							std::cout << "Account number: " << clients[i][j].getAccountNumber() << std::endl;
							std::cout << "Balance: " << clients[i][j].getBalance() << std::endl;
							std::cout << "Number of cards: " << clients[i][j].getCardsCount() << std::endl;

							if (clients[i][j].getCardsCount() == 0) {

								std::cout << "Client has no cards." << std::endl;
								return;
							}
							else {

								for (int k = 0; i < clients[i].getCardsCount(j); k++) {

									std::cout << "----Card" << k + 1 << "----" << std::endl;
									std::cout << "Card number: " << clients[i][k].getCardNumber(k) << std::endl;
									std::cout << "PIN: " << clients[i][k].getPIN(k) << std::endl;
									return;
								}
							}
						}
					}
				}
			}
		}
	}
	i_file.close();
	std::cout << "There's no such client with this EGN!" << std::endl;
}