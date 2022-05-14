#pragma warning(disable : 4996).
#include "Admin.h"

void Admin::input(const MyString& message, MyString& toInput) {

	std::cout << message;
	std::cin >> toInput;
}

Admin::Admin(MyString& username, MyString& password) : adminUsername(username), adminPassword(password) {}

void Admin::addAdminToFile(MyString& username, MyString& password) {

	std::ofstream o_file;
	o_file.open("Admins.txt", std::ios::app);

	if (!o_file.is_open()) {

		std::cout << "File could not be opened!" << std::endl;
	}

	adminUsername = username;

	adminPassword = password;

	o_file << adminUsername << " " << adminPassword << std::endl;

	o_file.close();
}

bool Admin::login(const char* filename) {

	std::cout << "Please, enter your username!" << std::endl;

	std::cin >> adminUsername;

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

		if (adminUsername == word) {

			std::cout << "Please, enter your password!" << std::endl;
			std::cin >> adminPassword;

			i_file.getline(word, BUFF_SIZE, ' ');
			if (adminPassword == word) {

				std::cout << "Success! :)" << std::endl;
				return true;
			}
			else {

				while (adminPassword != word) {

					std::cout << "Wrong password! Try again! :)" << std::endl;
					std::cin >> adminPassword;
				}
				std::cout << "Success! :)" << std::endl;
				return true;
			}
		}
		else {

			do {

				i_file.getline(word, BUFF_SIZE, ' ');

			} while (i_file.get() != '\n');
			continue;
		}
	}
	i_file.close();

	std::cout << "There's no such user!" << std::endl;
	return false;
}

void Admin::addEmployee(Employees& employees, MyString& egn, MyString& firstName, MyString& middleName, MyString& lastName,
	MyString& birthDate, MyString& telephoneNumber, MyString& address, MyString& username, MyString& password) { 

	std::ofstream o_file;
	o_file.open("Employees.txt", std::ios::app);

	if (!o_file.is_open()) {

		std::cout << "File could not be opened!" << std::endl;
		return;
	}

	std::cout << "To create an Employee - account please enter the following: " << std::endl;

	input("Username: ", username);
	input("Password: ", password);
	input("EGN: ", egn);

	std::ifstream i_file;
	i_file.open("Employees.txt");

	if (!i_file.is_open()) {

		std::cout << "File could not be opened!" << std::endl;
	}

	const int BUFF_SIZE = 1024;
	while (!i_file.eof())
	{
		char word[BUFF_SIZE];
		i_file.getline(word, BUFF_SIZE, ' ');

		if (egn == word) {

			std::cout << "Employee with this EGN exists!" << std::endl;
			return;
		}
		else {

			input("First name: ", firstName);
			input("Middle name: ", middleName);
			input("Last name: ", lastName);
			input("Birth date: ", birthDate);
			input("Telephone number: ", telephoneNumber);
			input("Address: ", address);

			employees.addEmployee(egn, firstName, middleName, lastName, birthDate, telephoneNumber, address, username, password);

			o_file << egn << " " << firstName << " " << middleName << " " << lastName << " " <<
				birthDate << " " << telephoneNumber << " " << address << " " << username << " " << password << " " << std::endl;
		 
			std::cout << "You have successfully added an Employee - account!" << std::endl;

			o_file.close();
			i_file.close();
			return;
		}
	}
}

void Admin::deleteEmployee(Employees& employees, MyString& egn) {

	input("Enter the EGN of the employee: ", egn);

	std::ifstream i_file;
	i_file.open("Employees.txt");

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
			for (int i = 0; i < employees.getCount(); i++) {

				if (employees[i].getEgn() == egn) {

					Employee toBeDeleted = employees[i];
					employees.deleteEmployee(toBeDeleted);
					std::cout << "Successfully deleted Employee." << std::endl;
					return;
				}
			}
		}
	}
	i_file.close();
	std::cout << "There's no employee with this EGN!" << std::endl;
}