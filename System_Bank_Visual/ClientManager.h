//ClientManager.h
#pragma once
#include <iostream>
#include <vector>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Validation.h"

using namespace std;


class ClientManager  {
public:
    static vector <Client*> clientList;
    static int currentClientId;


    static void printClientMenu() {
        cout << "\t\t\t\t\t   :: Client Menu ::\n";
        cout << "\t\t\t\t\t 1 - Deposit amount\n";
        cout << "\t\t\t\t\t 2 - Withdraw amount\n";
        cout << "\t\t\t\t\t 3 - Show balance\n";
        cout << "\t\t\t\t\t 4 - Transfer\n";
        cout << "\t\t\t\t\t 5 - Account information\n";
        cout << "\t\t\t\t\t 6 - Delete account\n";
        cout << "\t\t\t\t\t 7 - Exit\n";
    }

    static void updatePassword(Person* person) {
        string newPassword;
        cout << "Enter new password: ";
        cin >> newPassword;
        person->setPassword(newPassword);
        cout << "Password updated successfully.\n";
    }

    static Client* login(int id, string password) {
        Client* client = searchClientById(id);
        if (client) {
            if (client->getPassword() == password) {
                currentClientId = id;
                return client;
            }
            else {
                cout << "Invalid password.\n";
            }
        }
        return nullptr;
    }

    static bool clientOptions(Client* client) {
        int choice;
        char op;
        do {
            printClientMenu();
            cout << "\nEnter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                cout << "Deposit functionality coming soon.\n";
                break;
            case 2:
                cout << "Withdraw functionality coming soon.\n";
                break;
            case 3:
                client->checkBalance();
                break;
            case 4:
                transferAmount(client);
                break;
            case 5:
                client->Display();
                break;
            case 6:
                deleteClient(client->getId());
                return false;
            case 7:
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

    static void transferAmount(Client* sender) {
        int recipientId;
        double amount;
        cout << "Enter recipient ID: ";
        cin >> recipientId;

        Client* recipient = searchClientById(recipientId);
        if (recipient && recipientId != sender->getId()) {
            cout << "Enter amount to transfer: ";
            cin >> amount;
            if (amount > 0 && sender->getBalance() >= amount) {
                sender->transferTo(amount, *recipient);
                cout << "Transfer completed successfully.\n";
                cout << "Your new balance is: " << sender->getBalance() << endl;
            }
            else {
                cout << "Insufficient balance or invalid amount.\n";
            }
        }
        else {
            cout << "Recipient not found or invalid transfer.\n";
        }
    }

    static Client* searchClientById(int id) {
        if (id > 0 && id <= clientList.size()) {
            return clientList[id - 1];
        }
        else {
            cout << "Client with ID " << id << " not found.\n";
            return nullptr;
        }
    }

    static void deleteClient(int id) {
        Client* client = searchClientById(id);
        if (client) {
            char confirmation;
            cout << "Are you sure you want to delete this account? (Y/N): ";
            cin >> confirmation;
            confirmation = toupper(confirmation);
            if (confirmation == 'Y') {
                delete client;
                clientList.erase(clientList.begin() + id - 1);
                cout << "Client deleted successfully.\n";
            }
            else {
                cout << "Client deletion cancelled.\n";
            }
        }
        else {
            cout << "Invalid client ID.\n";
        }
    }

    static void listAllClients(Employee* employee = nullptr) {
        if (clientList.empty()) {
            cout << "No clients found.\n";
            return;
        }

        cout << "\nList of all clients:\n";
        for (int i = 0; i < clientList.size(); ++i) {
            cout << "Client " << i + 1 << ":\n";
            clientList[i]->Display();
            cout << "--------------------------\n";
        }
    }
};

