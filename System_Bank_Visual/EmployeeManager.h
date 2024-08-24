#pragma once
#include <iostream>
#include <vector>
#include "Employee.h"
#include "ClientManager.h"
//#include "FileManager.h"

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
        cout << "\t\t\t\t\t 5 - Internal Transfer\n";
        cout << "\t\t\t\t\t 6 - External Transfer\n";
        cout << "\t\t\t\t\t 7 - Delete client\n";
        cout << "\t\t\t\t\t 8 - Exit\n";
    }

    static void newClient(Employee* employee) {
        string name, password;
        double balance;
        int id = Client::getNewClientId();

        do {
            cout << "Enter client name: ";
            getline(cin, name);
        } while (!Validation::checkName(name));

        do {
            cout << "Enter client password: ";
            cin >> password;
        } while (!Validation::checkPassword(password));

        do {
            cout << "Enter client balance: ";
            cin >> balance;
        } while (!Validation::checkBalance(balance));

        Client* newClient = new Client(name, id, password, balance);
        ClientManager::clientList.push_back(newClient);

        cout << "Client account created successfully.\n";
        newClient->Display();
    }

    static void listAllClients() {
       //FileManager::getAllClients();
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
        int choice;
        string name, password;
        double balance;

        cout << "Enter client ID to edit: ";
        cin >> id;

        Client* client = ClientManager::searchClientById(id);
        if (client) {
            cout << "Select the information to edit:\n";
            cout << "1 - Name\n";
            cout << "2 - Password\n";
            cout << "3 - Balance\n";
            cout << "4 - Edit All\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, name);
                client->setName(name);
                cout << "Name updated successfully.\n";
                break;
            case 2:
                cout << "Enter new password: ";
                cin >> password;
                client->setPassword(password);
                cout << "Password updated successfully.\n";
                break;
            case 3:
                cout << "Enter new balance: ";
                cin >> balance;
                client->setBalance(balance);
                cout << "Balance updated successfully.\n";
                break;
            case 4:
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, name);
                client->setName(name);

                cout << "Enter new password: ";
                cin >> password;
                client->setPassword(password);

                cout << "Enter new balance: ";
                cin >> balance;
                client->setBalance(balance);

                cout << "All information updated successfully.\n";
                break;
            default:
                cout << "Invalid choice. No changes made.\n";
                return;
            }

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
                externalTransfer();
                break;
            case 6:
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

    static void externalTransfer() {
        string externalName;
        double amount;
        int recipientId;

        cout << "Enter external sender's name: ";
        cin.ignore(); 
        getline(cin, externalName);

        cout << "Enter amount to transfer: ";
        cin >> amount;
        if (amount <= 0) {
            cout << "Invalid amount. Amount must be greater than zero.\n";
            return;
        }

        cout << "Enter recipient ID: ";
        cin >> recipientId;

        Client* recipient = ClientManager::searchClientById(recipientId);
        if (!recipient) {
            cout << "Recipient not found.\n";
            return;
        }

        Client externalSender(externalName, 0, "", 0);

        if (amount > 0) {
            recipient->deposit(amount);
            cout << "Transfer completed successfully.\n";
            cout << "Transfer from " << externalName << " to " << recipient->getName() << " of amount " << amount << endl;
        }
        else {
            cout << "Failed to transfer. Amount must be greater than zero.\n";
        }
    }

 





};
