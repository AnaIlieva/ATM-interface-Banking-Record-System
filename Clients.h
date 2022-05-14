#pragma once
#ifndef CLIENTS_H
#define	CLIENTS_H

#include "Client.h"

class Clients {

private:
	std::vector<Client*> clients;

	void copy(const Clients& other);
	void free();

public:
	Clients() = default;
	Clients(const Clients& other);
	Clients& operator=(const Clients& other);
	~Clients();

	Client operator[](int pos) const;
	int getCount() const;
	void print();

	void addClient(Client& toBeAdded);
	void deleteClient(Client& toBeDeleted);
};

#endif