#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Admin.h"
#include "Employee.h"
#include "Client.h"
#include "Validation.h"
#include "EmployeeManager.h"
#include "ClientManager.h"


using namespace std;

class AdminManager {
public:
    static vector <Admin*> adminList;

    static void printAdminMenu() {
        cout << "\t\t\t\t\t   :: Admin Menu ::\n";
        cout << "\t\t\t\t\t 1 -  Add Employee\n";
        cout << "\t\t\t\t\t 2 -  Edit Employee Information\n";
        cout << "\t\t\t\t\t 3 -  Add Client\n";
        cout << "\t\t\t\t\t 4 -  Edit Client Information\n";
        cout << "\t\t\t\t\t 5 -  Search for Client\n";
        cout << "\t\t\t\t\t 6 -  Deposit for Client\n";
        cout << "\t\t\t\t\t 7 -  Withdraw from Client\n";
        cout << "\t\t\t\t\t 8 -  Internal Client Transfer\n";
        cout << "\t\t\t\t\t 9 -  External Client Transfer\n";
        cout << "\t\t\t\t\t 10 - List all Clients\n";
        cout << "\t\t\t\t\t 11 - List all Employees\n";
        cout << "\t\t\t\t\t 12 - List all Admins\n";
        cout << "\t\t\t\t\t 13 - Delete Client\n";
        cout << "\t\t\t\t\t 14 - Delete Employee\n";
        cout << "\t\t\t\t\t 15 - Exit\n";
    }

    static Admin* login(int id, string password) {
        Admin* admin = Admin::getInstance();
        if (admin->getPassword() == password) {
            return admin;
        }
        else {
            cout << "Invalid password.\n";
            return nullptr;
        }
    }

    static bool adminOptions() {
        int choice;
        char op;
        do {
            printAdminMenu();
            cout << "\nEnter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                editEmployeeInfo();
                break;
            case 3:
                EmployeeManager::newClient(nullptr);
                break;
            case 4:
                editClientInfo();
                break;
            case 5:
                searchForClient();
                break;
            case 6:

                EmployeeManager::depositToClient();
                break;
            case 7:
                EmployeeManager::withdrawFromClient();
                break;
            case 8:
                EmployeeManager::internalTransfer();
                break;
            case 9:
                EmployeeManager::externalTransfer();
                break;
            case 10:
                ClientManager::listAllClients(nullptr);
                break;
            case 11:
                listAllEmployees();
                break;
            case 12:
                listAllAdmins();
                break;
            case 13:
                deleteClient();
                break;
            case 14:
                deleteEmployee();
                break;
            case 15:
                cout << "Exiting system... Goodbye!\n";
                return false;
            default:
                cout << "Invalid choice, please try again.\n";
            }

            do {
                cout << "Press [Y] to Continue or [N] to Exit: ";
                cin >> op;
                op = toupper(op);
                if (op != 'Y' && op != 'N') {
                    cout << "Invalid input. Please enter 'Y' or 'N'.\n";
                }
            } while (op != 'Y' && op != 'N');

            if (op == 'N') {
                cout << "Exiting system... Goodbye!\n";
                return false;
            }

        } while (op == 'Y');

        return true;
    }

    static void addEmployee() {
        string name, password;
        int salary;
        cout << "Enter new employee name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter new employee password: ";
        cin >> password;

        cout << "Enter new employee salary: ";
        cin >> salary;

        int id = Employee::getNewEmployeeId();
        Employee* newEmployee = new Employee (name, id, password,salary);
        EmployeeManager::employeeList.push_back(newEmployee);

        cout << "Employee added successfully.\n";
        newEmployee->Display();
        newEmployee->getPassword();
    }

    static void editEmployeeInfo() {
        int id;
        string name, password;

        cout << "Enter employee ID to edit: ";
        cin >> id;

        if (id > 0 && id <= EmployeeManager::employeeList.size()) {
            Employee* employee = EmployeeManager::employeeList[id - 1];

            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter new password: ";
            cin >> password;

            employee->setName(name);
            employee->setPassword(password);

            cout << "Employee information updated successfully.\n";
            employee->Display();
        }
        else {
            cout << "Employee with ID " << id << " not found.\n";
        }
    }



    static void editClientInfo() {
        int id;
        string name, password;
        double balance;

        cout << "Enter client ID to edit: ";
        cin >> id;

        Client* client = ClientManager::searchClientById(id);
        if (client) {
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter new password: ";
            cin >> password;
            cout << "Enter new balance: ";
            cin >> balance;

            client->setName(name);
            client->setPassword(password);
            client->setBalance(balance);

            cout << "Client information updated successfully.\n";
            client->Display();
        }
        else {
            cout << "Client with ID " << id << " not found.\n";
        }
    }

    static void searchForClient() {
        int id;
        cout << "Enter client ID to search: ";
        cin >> id;

        Client* client = ClientManager::searchClientById(id);
        if (client) {
            client->Display();
        }
        else {
            cout << "Client with ID " << id << " not found.\n";
        }
    }

    static void listAllEmployees() {
        EmployeeManager::listAllEmployees(nullptr);
    }

    static void listAllClients() {
        ClientManager::listAllClients(nullptr);
    }

    static void listAllAdmins(Employee* employee = nullptr) {
        if (adminList.empty()) {
            cout << "No Admins found.\n";
            return;
        }

        cout << "\nList of all Admins:\n";
        for (int i = 0; i < adminList.size(); ++i) {
            cout << "Admin " << i + 1 << ":\n";
            adminList[i]->Display();
            cout << "--------------------------\n";
        }
    }

    static void deleteClient() {
        int id;
        cout << "Enter the Client ID to delete: ";
        cin >> id;
        ClientManager::deleteClient(id);
    }

    static void deleteEmployee() {

        EmployeeManager::deleteEmployee();
    }


};
