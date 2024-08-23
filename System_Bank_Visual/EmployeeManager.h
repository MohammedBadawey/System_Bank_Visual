#pragma once
#include <iostream>
#include <vector>
#include "Employee.h"
#include "ClientManager.h"
#include "Parser.h"
#include "Validation.h"

using namespace std;

class EmployeeManager {
public:
    static vector <Employee*> employeeList;
    
    static void printEmployeeMenu() {
        cout << "\t\t\t\t\t   :: Employee Menu ::\n";
        cout << "\t\t\t\t\t 1 - Add new client\n";
        cout << "\t\t\t\t\t 2 - List all clients\n";
        cout << "\t\t\t\t\t 3 - Search for client\n";
        cout << "\t\t\t\t\t 4 - Edit client information\n";
        cout << "\t\t\t\t\t 5 - Exit\n";
    }

    static void newClient(Employee* employee) {
        string name, password;
        double balance;
        int id = Client::getNewClientId();

        Validation::ValidationData(name, password, balance, "Client");
        Client* newClient = new Client(name, id, password, balance);
        ClientManager::clientList.push_back(newClient);
        cout << "Client account created successfully.\n";
        newClient->Display();
    }

    static void listAllClients() {
        ClientManager::listAllClients(nullptr);
    }

    static void searchForClient(Employee* employee) {
        int id;
        cout << "Enter client ID: ";
        cin >> id;

        Client* client = ClientManager::searchClientById(id);
        if (client) {
            client->Display();
        }
        else {
            cout << "Client with ID " << id << " not found.\n";
        }
    }

    static void editClientInfo(Employee* employee) {
        int id;
        string name, password;
        double balance;

        cout << "Enter client ID to edit: ";
        cin >> id;

        Client* client = ClientManager::searchClientById(id);
        if (client) {
            cout << "Enter new name: ";
            cin >> name;
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

    static Employee* login(int id, string password) {
        if (id > 0 && id <= employeeList.size()) {
            Employee* employee = employeeList[id - 1];
            if (employee->getPassword() == password) {
                return employee;
            }
            else {
                cout << "Invalid password.\n";
                return nullptr;
            }
        }
        else {
            cout << "Invalid ID.\n";
            return nullptr;
        }
    }

    static bool employeeOptions(Employee* employee) {
        int choice;
        char op;
        do {
            printEmployeeMenu();
            cout << "\nEnter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                newClient(employee);
                break;
            case 2:
                listAllClients();
                break;
            case 3:
                searchForClient(employee);
                break;
            case 4:
                editClientInfo(employee);
                break;
            case 5:
                cout << "Exiting system... Goodbye!\n";
                return false;  // Exit the employee menu
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
                return false;  // Exit the employee menu
            }

        } while (op == 'Y');

        return true;  // Continue in case of 'Y'
    }

};
