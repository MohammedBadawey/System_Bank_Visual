//Parser.h
#pragma once
#include <fstream>
#include <vector>
#include "Admin.h"

using namespace std;


class Parser
{
public:
	
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
		return admin;
	}
};

