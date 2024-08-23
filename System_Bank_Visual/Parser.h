#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ClientManager.h"

using namespace std;


class Parser
{
public:

	static vector <Client*> clients;


	static void saveClient(Client* c) {
		ofstream ofS("clientData.txt", ios::app);
		if (ofS) {
			ofS << c->getId() << "|" << c->getName() << "|" << c->getPassword() << "|" << c->getBalance() << endl;
		}
		else {
			cout << "Error opening Clients.txt for writing!" << endl;
		}
	}

	static void readClient() {
		ifstream ifS("clientData.txt");
		if (!ifS) {
			cout << "Error opening clientData.txt for reading!" << endl;
			return;
		}

		string line;
		while (getline(ifS, line)) {
			Client* client = new Client(parseToClient(line));
			clients.push_back(client);
			ClientManager::clientList.push_back(client);
		}
	}

	static vector<string> split(const string& line) {
		char delimiter = '|';
		vector<string> tokens;
		int start = 0;
		int pos = line.find(delimiter);

		while (pos != string::npos) {
			string myCut = line.substr(start, pos - start);
			tokens.push_back(myCut);
			start = pos + 1;
			pos = line.find(delimiter, start);
		}
		tokens.push_back(line.substr(start));


		return tokens;
	}

	static Client parseToClient(const string& line) {
		vector<string> parts = split(line);
		if (parts.size() != 4) {
			cout << "Incorrect data format";
			return Client("", -1, "", 0);
		}

		int id = stoi(parts[0]);
		string name = parts[1];
		string password = parts[2];
		int balance = stod(parts[3]);

		return Client(name, id, password, balance);
	}


};

