#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Functions.h"

using namespace std;

class Parser {
public:
	static void saveData (Client* c) {
		ofstream ofClient;
		ofClient.open("ClintData.txt", ios::app);
		if (ofClient.is_open()) {
			ofClient << c->getId() << "->" << c->getName() << "->" << c->getPassword() << "->" << c->getBalance() << endl;
			ofClient.close();
		} else { cout << "Error opening file for writing!" << endl; }
	}

	static void openData() {
		ifstream ifClient("ClintData.txt");
		string line;

		if (ifClient.is_open()) {
			while (getline(ifClient, line)) {
				vector<string> clientData = split(line);
				Client client = parseToClient(line);
			}
			ifClient.close();
		}
		else {
			cout << "Error opening file for reading!" << endl;
		}
	}


	static vector<string> split(string line) {
		vector<string> result;
		size_t pos = 0;
		string token;
		while ((pos = line.find("->")) != string::npos) {
			token = line.substr(0, pos);
			result.push_back(token);
			line.erase(0, pos + 2);
		}
		result.push_back(line);
		return result;
	}



	static Client parseToClient(string line) {
		vector<string> tokens = split(line);

		if (tokens.size() == 4) {
			int id = stoi(tokens[0]);
			string name = tokens[1];
			string password = tokens[2];
			double balance = stod(tokens[3]);

			return Client(name, id, password, balance);
		}
		else {
			cout << "Invalid line format" << endl;
			return Client("", -1, "", 0.0);
		}
	}


};

