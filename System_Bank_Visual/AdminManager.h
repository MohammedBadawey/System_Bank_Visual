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
    static vector<Admin*> adminList;

    static void printAdminMenu() {
        cout << "\t\t\t\t\t   :: Admin Menu ::\n";
        cout << "\t\t\t\t\t 1 - Add Employee\n";
        cout << "\t\t\t\t\t 2 - Edit Employee Information\n";
        cout << "\t\t\t\t\t 3 - Add Client\n";
        cout << "\t\t\t\t\t 4 - Edit Client Information\n";
        cout << "\t\t\t\t\t 5 - List all Employees\n";
        cout << "\t\t\t\t\t 6 - List all Clients\n";
        cout << "\t\t\t\t\t 7 - Employee Menu\n";
        cout << "\t\t\t\t\t 8 - Exit\n";
    }

    static void printEmployeeMenu() {
        EmployeeManager::printEmployeeMenu();
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
        Admin* admin = Admin::getInstance();

        do {
            printAdminMenu();
            cout << "\nEnter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1: {
                // Add Employee
                string name, password;
                double salary;
                int id;
                cout << "Enter employee name: ";
                cin >> name;
                cout << "Enter employee ID: ";
                cin >> id;
                cout << "Enter employee password: ";
                cin >> password;
                cout << "Enter employee salary: ";
                cin >> salary;
                Employee* employee = new Employee(name, id, password, salary);
                admin->addEmployee(*employee);
                cout << "Employee added successfully.\n";
                delete employee;
                break;
            }

            case 2: {
                // Edit Employee Information
                int id;
                string name, password;
                double salary;
                cout << "Enter employee ID to edit: ";
                cin >> id;
                cout << "Enter new employee name: ";
                cin >> name;
                cout << "Enter new employee password: ";
                cin >> password;
                cout << "Enter new employee salary: ";
                cin >> salary;
                admin->editEmployee(id, name, password, salary);
                break;
            }

            case 3: {
                // Add Client
                string name, password;
                double balance;
                int id;
                cout << "Enter client name: ";
                cin >> name;
                cout << "Enter client ID: ";
                cin >> id;
                cout << "Enter client password: ";
                cin >> password;
                cout << "Enter client balance: ";
                cin >> balance;
                Client* client = new Client(name, id, password, balance);
                admin->addClient(*client);
                cout << "Client added successfully.\n";
                delete client;
                break;
            }

            case 4: {
                // Edit Client Information
                int id;
                string name, password;
                double balance;
                cout << "Enter client ID to edit: ";
                cin >> id;
                cout << "Enter new client name: ";
                cin >> name;
                cout << "Enter new client password: ";
                cin >> password;
                cout << "Enter new balance: ";
                cin >> balance;
                admin->editClient(id, name, password, balance);
                break;
            }

            case 5: {
                // List all Employees
                admin->listEmployee();
                break;
            }

            case 6: {
                // List all Clients
                admin->listClient();
                break;
            }

            case 7: {
                cout << "Exiting system... Goodbye!\n";
                return false;
            }

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
};
