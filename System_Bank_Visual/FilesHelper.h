#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"
#include "ClientManager.h"
#include "EmployeeManager.h"
#include "AdminManager.h"


using namespace std;

class FilesHelper {
public:
    static vector <Client*> clients;
    static vector<Employee*> employees;
    static vector<Admin*> admins;

    static void saveLast(const string& fileName, int id) {
        ofstream ofs(fileName);
        if (ofs.is_open()) {
            ofs << id << endl;
        }
        else {
            cout << "Error opening " << fileName << " for writing!" << endl;
        }
    }

    static int getLast(const string& fileName) {
        ifstream ifs(fileName);
        if (!ifs.is_open()) {
            cout << "Error opening " << fileName << " for reading!" << endl;
            return -1;
        }

        int id;
        ifs >> id;
        return id;
    }

    static void saveClient(Client* c) {
        ofstream ofS("clientData.txt", ios::app);
        if (ofS.is_open()) {
            ofS << c->getId() << "|" << c->getName() << "|" << c->getPassword() << "|" << c->getBalance() << endl;
        }
        else {
            cout << "Error opening clientData.txt for writing!" << endl;
        }
    }

    static void saveEmployee(Employee* e) {
        ofstream ofS("employeeData.txt", ios::app);
        if (ofS.is_open()) {
            ofS << e->getId() << "|" << e->getName() << "|" << e->getPassword() << "|" << e->getSalary() << endl;
        }
        else {
            cout << "Error opening employeeData.txt for writing!" << endl;
        }
    }

    static void saveAdmin(Admin* a) {
        ofstream ofs("adminData.txt", ios::app);
        if (ofs.is_open()) {
            ofs << a->getId() << "|" << a->getName() << "|" << a->getPassword() << "|" << a->getSalary() << endl;
        }
        else {
            cout << "Error opening adminData.txt for writing!" << endl;
        }
    }

    static void getClients() {
        ifstream ifs("clientData.txt");
        if (!ifs.is_open()) {
            cout << "Error opening clientData.txt for reading!" << endl;
            return;
        }

        string line;
        while (getline(ifs, line)) {
            Client* c = new Client (Parser::parseToClient(line));
            clients.push_back(c);
            ClientManager::clientList.push_back(c);
        }
    }

    static void getEmployees() {
        ifstream ifs("employeeData.txt");
        if (!ifs.is_open()) {
            cout << "Error opening employeeData.txt for reading!" << endl;
            return;
        }

        string line;
        while (getline(ifs, line)) {
            Employee* e = new Employee (Parser::parseToEmployee(line));
            employees.push_back(e);
            EmployeeManager::employeeList.push_back(e);
        }
    }

    static void getAdmins() {
        ifstream ifs("adminData.txt");
        if (!ifs.is_open()) {
            cout << "Error opening adminData.txt for reading!" << endl;
            return;
        }

        string line;
        while (getline(ifs, line)) {
            Admin* admin = Admin::getInstance();
            admin = Parser::parseToAdmin(line);
            AdminManager::adminList.push_back(admin);
        }
    }

    static void clearFile(const string& fileName, const string& lastIdFile) {
        ofstream ofs(fileName, ios::trunc);
        if (!ofs.is_open()) {
            cout << "Error opening " << fileName << " for clearing!" << endl;
        }
        ofs.close();

        saveLast(lastIdFile, -1);
    }

};
