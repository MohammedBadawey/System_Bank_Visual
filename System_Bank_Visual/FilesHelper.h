#pragma once
#include "Parser.h"
#include "GlobalVectors.h"


using namespace std;

class FilesHelper {
public:


    static void saveLast(const string& fileName, int id) {
        ofstream* ofs = new ofstream(fileName);

        if (ofs->is_open()) {
            *ofs << id << endl;
            ofs->close();
        }
        else {
            cout << "Error opening " << fileName << " for writing!" << endl;
        }

        delete ofs;
    }

    static int getLast(const string& fileName) {
        ifstream* ifs = new ifstream(fileName);

        if (!ifs->is_open()) {
            cout << "Error opening " << fileName << " for reading!" << endl;
            delete ifs;
            return -1;
        }

        else {
            int id;
            *ifs >> id;

            ifs->close();
            return id;
        }
        delete ifs;
    }

    static void saveClient(Client* c) {
        ofstream* ofs = new ofstream("clientData.txt", ios::app);

        if (ofs->is_open()) {
            *ofs << c->getId() << "|" << c->getName() << "|" << c->getPassword() << "|" << c->getBalance() << endl;
            ofs->close();

            int i = c->getId();
            saveLast("lastClientId.txt", i);
        }
        else {
            cout << "Error opening clientData.txt for writing!" << endl;
        }

        delete ofs;
    }

    static void saveEmployee(Employee* e) {
        ofstream* ofs = new ofstream("employeeData.txt", ios::app);
        if (ofs->is_open()) {
            *ofs << e->getId() << "|" << e->getName() << "|" << e->getPassword() << "|" << e->getSalary() << endl;
            ofs->close();
            int i = e->getId();
            saveLast("lastEmployeeId.txt", i);
        }
        else {
            cout << "Error opening employeeData.txt for writing!" << endl;
        }
        delete ofs;
    }

    static void saveAdmin(Admin* a) {
        ofstream* ofs = new ofstream("adminData.txt", ios::app);
        if (ofs->is_open()) {
            *ofs << a->getId() << "|" << a->getName() << "|" << a->getPassword() << "|" << a->getSalary() << endl;
            ofs->close();
            int i = a->getId();
            saveLast("lastAdminId.txt", i);
        }
        else {
            cout << "Error opening adminData.txt for writing!" << endl;
        }
        delete ofs;
    }

    static void getClients() {
        ifstream* ifs = new ifstream("clientData.txt");
        if (!ifs->is_open()) {
            cout << "Error opening clientData.txt for reading!" << endl;
            return;
        }

        string line;
        while (getline(*ifs, line)) {
            Client* c = new Client (Parser::parseToClient(line));
            clientList.push_back(c);
        }
        ifs->close();
        delete ifs;
    }

    static void getEmployees() {
        ifstream* ifs = new ifstream("employeeData.txt");
        if (!ifs->is_open()) {
            cout << "Error opening employeeData.txt for reading!" << endl;
            return;
        }

        string line;
        while (getline(*ifs, line)) {
            Employee* e = new Employee (Parser::parseToEmployee(line));
            employeeList.push_back(e);
        }
        ifs->close();
        delete ifs;
    }

    static void getAdmins() {
        ifstream* ifs = new ifstream("adminData.txt");
        if (!ifs->is_open()) {
            cout << "Error opening adminData.txt for reading!" << endl;
            return;
        }

        string line;
        while (getline(*ifs, line)) {
            Admin* admin = Admin::getInstance();
            Admin tempAdmin = *Parser::parseToAdmin(line);


            admin->setId(tempAdmin.getId());
            admin->setName(tempAdmin.getName());
            admin->setPassword(tempAdmin.getPassword());
            admin->setSalary(tempAdmin.getSalary());

            adminList.push_back(admin);
        }
        ifs->close();
        delete ifs;
    }

    static void clearFile(const string& fileName, const string& lastIdFile) {
        ofstream* ofs = new ofstream(fileName, ios::trunc);
        if (!ofs->is_open()) {
            cout << "Error opening " << fileName << " for clearing!" << endl;
        }
        ofs->close();
        saveLast(lastIdFile, 0);
        delete ofs;
    }

};
