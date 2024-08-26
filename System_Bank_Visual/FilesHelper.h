#pragma once
#include "Parser.h"
#include "GlobalVectors.h"


using namespace std;

class FilesHelper {
public:


    static void saveLast(const string& fileName, int id) {
        ofstream ofs(fileName);
        if (ofs.is_open()) {
            ofs << id << endl;
            ofs.close();
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
        ifs.close();
        return id;
    }

    static void saveClient(Client* c) {
        ofstream ofS("clientData.txt", ios::app);
        if (ofS.is_open()) {
            ofS << c->getId() << "|" << c->getName() << "|" << c->getPassword() << "|" << c->getBalance() << endl;
            ofS.close();
            int i = c->getId();
            saveLast("lastClientId.txt",i );
        }
        else {
            cout << "Error opening clientData.txt for writing!" << endl;
        }

    }

    static void saveEmployee(Employee* e) {
        ofstream ofS("employeeData.txt", ios::app);
        if (ofS.is_open()) {
            ofS << e->getId() << "|" << e->getName() << "|" << e->getPassword() << "|" << e->getSalary() << endl;
            ofS.close();
            saveLast("lastEmployeeId.txt", e->getId());
        }
        else {
            cout << "Error opening employeeData.txt for writing!" << endl;
        }
        saveLast("lastEmployeeId.txt", e->getId());
    }

    static void saveAdmin(Admin* a) {
        ofstream ofs("adminData.txt", ios::app);
        if (ofs.is_open()) {
            ofs << a->getId() << "|" << a->getName() << "|" << a->getPassword() << "|" << a->getSalary() << endl;
            ofs.close();
            saveLast("lastAdminId.txt", a->getId());
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
            clientList.push_back(c);
        }
        ifs.close();

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
            employeeList.push_back(e);
        }
        ifs.close();
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
            Admin tempAdmin = *Parser::parseToAdmin(line);


            admin->setId(tempAdmin.getId());
            admin->setName(tempAdmin.getName());
            admin->setPassword(tempAdmin.getPassword());
            admin->setSalary(tempAdmin.getSalary());

            adminList.push_back(admin);
        }
        ifs.close();
    }

    static void clearFile(const string& fileName, const string& lastIdFile) {
        ofstream ofs(fileName, ios::trunc);
        if (!ofs.is_open()) {
            cout << "Error opening " << fileName << " for clearing!" << endl;
        }
        ofs.close();

        saveLast(lastIdFile, 0);
    }

};
