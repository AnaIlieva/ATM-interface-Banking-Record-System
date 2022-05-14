#pragma warning(disable : 4996).
#include "Clients.h"

void Clients::copy(const Clients& other) {

	for (int i = 0; i < other.clients.size(); i++) {

		clients.push_back(other.clients[i]->clone());
	}
}

void Clients::free() {

	for (int i = 0; i < clients.size(); i++) {

		delete clients[i];
	}
	clients.clear();
}

Clients::Clients(const Clients& other) {

	copy(other);
}

Clients& Clients::operator=(const Clients& other) {

	if (this != &other) {

		free();
		copy(other);
	}
	return *this;
}

Clients::~Clients() {

	free();
}

Client Clients::operator[](int pos) const {

	return *clients.operator[](pos);
}

int Clients::getCount() const {

	return clients.size();
}

void Clients::print() {

	for (int i = 0; i < clients.size(); i++) {

		clients[i]->print();
	}
}

void Clients::addClient(Client& toBeAdded) {

	Client* pointer = new Client(toBeAdded);
	clients.push_back(pointer);
}

void Clients::deleteClient(Client& toBeDeleted) {

	int index = 0;
	for (int i = 0; i < clients.size(); i++) {

		if (clients[i] == &toBeDeleted) {

			index = i;
		}
	}

	clients.erase(clients.begin() + index);
}