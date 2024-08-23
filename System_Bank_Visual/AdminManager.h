#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Admin.h"
#include "Validation.h"
#include "EmployeeManager.h"
#include "ClientManager.h"


using namespace std;

class AdminManager {
public:
    static vector <Admin*> adminList;

    static void printAdminMenu() {
        cout << "\t\t\t\t\t   :: Admin Menu ::\n";
        cout << "\t\t\t\t\t 1 - Add Employee\n";
        cout << "\t\t\t\t\t 2 - Search Client\n";
        cout << "\t\t\t\t\t 3 - Edit Client Info\n";
        cout << "\t\t\t\t\t 4 - List Clients\n";
        cout << "\t\t\t\t\t 5 - Exit\n";
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
                cout << "Adding employee functionality is not implemented yet.\n";
                break;
            case 2: {
                int clientId;
                cout << "Enter client ID to search: ";
                cin >> clientId;
                Client* foundClient = ClientManager::searchClientById(clientId);
                if (foundClient) {
                    foundClient->Display();
                }
                break;
            }
            case 3:
                editClientInfo();
                break;
            case 4:
                listAllClients();
                break;
            case 5:
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

    static void editClientInfo() {
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

    static void listAllClients() {
        ClientManager::listAllClients(nullptr);
    }
};
