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
        do {
            printAdminMenu();
            cout << "\nEnter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                //addEmployee();
                break;
            case 2:
                //editEmployeeInfo();
                break;
            case 3:
                EmployeeManager::newClient(nullptr);
                break;
            case 4:
               // editClientInfo();
                break;
            case 5:
                //searchForClient();
                break;
            case 6:
                EmployeeManager::externalTransfer();
                break;
            case 7:
              //  ClientManager::listAllClients(nullptr);
                break;
            case 8:
                //listAllEmployees();
                break;
            case 9:
              //  listAllAdmins();
                break;
            case 10:
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










};
