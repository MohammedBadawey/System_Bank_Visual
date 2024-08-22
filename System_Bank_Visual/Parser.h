#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
#include "Client.h"


using namespace std;

//class Functions;
//class Parser
//{
//public:
//	static void saveClient(Client* c) {
//		ofstream ofS("Clients.txt", ios::app);
//		if (ofS) {
//			ofS << c->getId() << "|" << c->getName() << "|" << c->getPassword() << "|" << c->getBalance() << endl;
//		}
//		else {
//			cout << "Error opening Clients.txt for writing!" << endl;
//		}
//	}
//
//	static void readClient() {
//		ifstream ifS;
//		ifS.open("clientData.txt");
//		string line;
//		string myClient[4];
//
//		while (getline(ifS, line)) {
//			int pos = 0;
//			string split;
//			int index = 0;
//			while (pos != -1) {
//				pos = line.find("|");
//				split = line.substr(0, pos);
//				line = line.substr(pos + 1);
//				myClient[index] = split;
//				index++;
//			};
//			int id = stoi(myClient[0]);
//			string name = myClient[1];
//			string password = myClient[2];
//			int balance = stoi(myClient[3]);
//			vector <Client*> readClient;
//			Client* newClient = new Client(name, id, password, balance);
//			readClient.push_back(newClient);
//		};
//
//		
//	}
//
//
//
//
//};

