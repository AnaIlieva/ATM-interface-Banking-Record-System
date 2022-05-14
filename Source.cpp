#pragma once
#pragma warning(disable : 4996).

#include "StartProgramm.h"

const int MAX_FILENAME_LEN = 200;

void backOrExit(Admin& a, Employee& e, Client& c, const char* filenameClients, const char* filenameEmployees,
                    const char* filenameAdmins, Employees& employees, Clients& clients) {

    std::cout << "Enter 'back' to return to the menu or 'exit' to finish: " << std::endl;
    MyString command;
    std::cin >> command;

    if (command == "back") {

        startProgramm(a, e, c, filenameClients, filenameEmployees, filenameAdmins, employees, clients);
    }
    else if (command == "exit") {

        return;
    }
    else {

        std::cout << "Wrong command!" << std::endl;
        return;
    }
}

void admin(MyString& egn, MyString& firstName, MyString& middleName, MyString& lastName, MyString& birthDate, 
            MyString& telephoneNumber, MyString& address, MyString& username, MyString& password, Admin& a, const char* filenameAdmins, Employees& employees) {

    if (a.login(filenameAdmins)) {

        std::cout << "Enter 'help' for more information!" << std::endl;
        MyString expression;
        std::cin >> expression;

        if (expression == "help") {

            std::cout << "Choose your next move: " << std::endl;
            std::cout << "Add new employee - account or Delete an existing employee - account (Type Add or Delete) " << std::endl;

            MyString addOrDeleteCommand;
            std::cin >> addOrDeleteCommand;

            if (addOrDeleteCommand == "Add") {

                a.addEmployee(employees, egn, firstName, middleName, lastName, birthDate, telephoneNumber, address, username, password);
            }

            if (addOrDeleteCommand == "Delete") {

                a.deleteEmployee(employees, egn);
            }
        }
    }
}

void employee(MyString& egn, MyString& firstName, MyString& middleName, MyString& lastName, MyString& birthDate, MyString& telephoneNumber,
                MyString& address, Employee& e, double amount, MyString accountNumber, MyString cardNumber, const char* filenameEmployees, Clients& clients) {

    if (e.login(filenameEmployees)) {

        std::cout << "Enter 'help' for more information!" << std::endl;
        MyString expression;
        std::cin >> expression;

        if (expression == "help") {

            std::cout << "Choose your next move: " << std::endl;
            std::cout << "Add or delete client - account" << std::endl;
            std::cout << "Opening an account" << std::endl;
            std::cout << "Add card to an account" << std::endl;
            std::cout << "Closing an account" << std::endl;
            std::cout << "Delete card from an account" << std::endl;
            std::cout << "Bank report" << std::endl;
            std::cout << "Individual client report" << std::endl;

            MyString employeeCommand;
            std::cin >> employeeCommand;

            if (employeeCommand == "Add") {

                e.addClient(clients, egn, firstName, middleName, lastName, birthDate, telephoneNumber, address);
            }

            if (employeeCommand == "Delete") {

                e.deleteClient(clients, egn);
            }

            if (employeeCommand == "Opening an account") {

                e.openAnAccount(egn, amount, clients);
            }

            if (employeeCommand == "Add card to an account") {

                e.addCardToAccount(egn, accountNumber, clients);
            }

            if (employeeCommand == "Closing an account") {

                e.deleteAnAccount(egn, accountNumber, clients);
            }

            if (employeeCommand == "Delete card from an account") {

                e.deleteCardFromAccount(egn, accountNumber, cardNumber, clients);
            }

            if (employeeCommand == "Bank report") {

                e.printBankReport(clients);
            }

            if (employeeCommand == "Individual client report") {

                e.printIndividualReport(egn, clients);
            }
        }
    }
}

void client(Client& c, double amount, const char* filenameClients, MyString& PIN) {

    if (c.login(filenameClients, PIN)) {

        std::cout << "Enter 'help' for more information!" << std::endl;
        MyString expression;
        std::cin >> expression;

        if (expression == "help") {

            std::cout << "Choose your next move: " << std::endl;
            std::cout << "Deposit" << std::endl;
            std::cout << "Withdraw" << std::endl;
            std::cout << "Check balance" << std::endl;

            MyString clientCommand;
            std::cin >> clientCommand;

            if (clientCommand == "Deposit") {

               c.deposit(amount, PIN);
            }

            if (clientCommand == "Withdraw") {

                c.withdraw(amount, PIN);
            }

            if (clientCommand == "Check balance") {

               c.checkBalance(PIN);
            }
        }
    }
}

void startProgramm(Admin& a, Employee& e, Client& c, const char* filenameClients, const char* filenameEmployees,
    const char* filenameAdmins, Employees& employees, Clients& clients) {

    MyString egn;
    MyString firstName;
    MyString middleName;
    MyString lastName;
    MyString birthDate;
    MyString telephoneNumber;
    MyString address;
    MyString username;
    MyString password;
    double amount = 0;
    MyString accountNumber;
    MyString cardNumber;
    MyString PIN;

    std::cout << "Choose your next move: " << std::endl;
    std::cout << "loginAsAdmin" << std::endl;
    std::cout << "loginAsEmployee" << std::endl;
    std::cout << "loginAsClient" << std::endl;

    MyString command;
    std::cin >> command;

    if (command == "loginAsAdmin") {

        admin(egn, firstName, middleName, lastName, birthDate, telephoneNumber, address, username, password, a, filenameAdmins, employees);
        backOrExit(a, e, c, filenameClients, filenameEmployees, filenameAdmins, employees, clients);
    }
    else if (command == "loginAsEmployee") {

        employee(egn, firstName, middleName, lastName, birthDate, telephoneNumber, address, e, amount, accountNumber, cardNumber, filenameEmployees, clients);
        backOrExit(a, e, c, filenameClients, filenameEmployees, filenameAdmins, employees, clients);
    }
    else if (command == "loginAsClient") {

        client(c, amount, filenameClients, PIN);
        backOrExit(a, e, c, filenameClients, filenameEmployees, filenameAdmins, employees, clients);
    }
    else {

        std::cout << "Wrong command!" << std::endl;
        return;
    }
}

int main() {

    const char filenameClients[MAX_FILENAME_LEN] = "Clients.txt";
    const char filenameEmployees[MAX_FILENAME_LEN] = "Employees.txt";
    const char filenameAdmins[MAX_FILENAME_LEN] = "Admins.txt";
    const char filenameAccounts[MAX_FILENAME_LEN] = "Client'sAccounts.txt";

    Employees employees;
    Clients clients;

    MyString identification = "admin";
    Admin a(identification, identification);

    //a.addAdminToFile("admin", "admin");

    Employee e("123456", "Ana", "Borisova", "Ilieva", "30.09.2001", "123", "Sofia", "ani", "ani");
    employees.addEmployee("123456", "Ana", "Borisova", "Ilieva", "30.09.2001", "123", "Sofia", "ani", "ani");

    Client c("test", "test", "test", "test", "test", "test", "test");
    clients.addClient(c);

    startProgramm(a, e, c, filenameClients, filenameEmployees, filenameAdmins, employees, clients);
}
