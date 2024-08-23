//Parser.h
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ClientManager.h"
#include "EmployeeManager.h"
#include "AdminManager.h"

using namespace std;

class Parser
{
public:
	static vector <Client*> clients;
	static vector<Employee*> employees;
	static vector<Admin*> admins;

	static void saveClient(Client* c) {
		ofstream ofS("clientData.txt", ios::app);
		if (ofS) {
			ofS << c->getId() << "|" << c->getName() << "|" << c->getPassword() << "|" << c->getBalance() << endl;
		}
		else {
			cout << "Error opening ClientsData.txt for writing!" << endl;
		}
	}

	static void saveEmployee(Employee* e) {
		ofstream ofS("employeeData.txt", ios::app);
		if (ofS) {
			ofS << e->getId() << "|" << e->getName() << "|" << e->getPassword() << "|" << e->getSalary() << endl;
		}
		else {
			cout << "Error opening EmployeeData.txt for writing!" << endl;
		}
	}

	static void saveAdmin(Admin* a) {
		ofstream ofS("adminData.txt", ios::app);
		if (ofS) {
			ofS << a->getId() << "|" << a->getName() << "|" << a->getPassword() << "|" << a->getSalary() << endl;
		}
		else {
			cout << "Error opening adminData.txt for writing!" << endl;
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

	static void readEmployee() {
		ifstream ifS("employeeData.txt");
		if (!ifS) {
			cout << "Error opening employeeData.txt for reading!" << endl;
			return;
		}

		string line;
		while (getline(ifS, line)) {
			Employee* newEmployee = new Employee(parseToEmployee(line));
			employees.push_back(newEmployee);
			EmployeeManager::employeeList.push_back(newEmployee);
		}
	}

	static void readAdmin() {
		ifstream ifS("adminData.txt");
		if (!ifS) {
			cout << "Error opening adminData.txt for reading!" << endl;
			return;
		}

		string line;
		if (getline(ifS, line)) {
			Admin* admin = Admin::getInstance();
			admin = parseToAdmin(line);  
			AdminManager::adminList.push_back(admin);
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
			cout << "Incorrect client data format";
			return Client("", -1, "", 0);
		}

		int id = stoi(parts[0]);
		string name = parts[1];
		string password = parts[2];
		int balance = stod(parts[3]);

		return Client(name, id, password, balance);
	}

	static Employee parseToEmployee(const string& line) {
		vector<string> parts = split(line);
		if (parts.size() != 4) {
			cout << "Incorrect employee data format";
			return Employee("", -1, "", 0);
		}

		int id = stoi(parts[0]);
		string name = parts[1];
		string password = parts[2];
		double salary = stod(parts[3]);

		return Employee(name, id, password, salary);
	}

	static Admin* parseToAdmin(const string& line) {
		vector<string> parts = split(line);
		if (parts.size() != 4) {
			cout << "Incorrect admin data format" << endl;
			return nullptr;
		}

		int id = stoi(parts[0]);
		string name = parts[1];
		string password = parts[2];
		int level = stoi(parts[3]);

		Admin* admin = Admin::getInstance(name, id, password, level);
		saveAdmin(admin);
		return admin;
	}

	static void createClient() {
		string name, password;
		double balance;
		int id = Client::getNewClientId();

		Validation::ValidationData(name, password, balance, "Client");
		Client* newClient = new Client(name, id, password, balance);
		ClientManager::clientList.push_back(newClient);
		saveClient(newClient);
		cout << "Client account created successfully.\n";
		newClient->Display();
	}

	




};

