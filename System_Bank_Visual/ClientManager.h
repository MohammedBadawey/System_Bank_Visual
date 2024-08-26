#pragma once
#include "Employee.h"




using namespace std;


class ClientManager  {
public:
    static int currentClientId;




    static void printClientMenu() {
        cout << "\t\t\t\t\t   :: Client Menu ::\n";
        cout << "\t\t\t\t\t 1 - Deposit amount\n";
        cout << "\t\t\t\t\t 2 - Withdraw amount\n";
        cout << "\t\t\t\t\t 3 - Show balance\n";
        cout << "\t\t\t\t\t 4 - Transfer\n";
        cout << "\t\t\t\t\t 5 - Account information\n";
        cout << "\t\t\t\t\t 6 - Exit\n";
    }

    static void updatePassword(Person* person) {
        string oldPassword, newPassword;

        cout << "Enter your current password: ";
        cin.ignore();
        getline(cin, oldPassword);

        if (person->getPassword() != oldPassword) {
            cout << "Incorrect current password.\n";
            return;
        }

        do {
            cout << "Enter new password: ";
            getline(cin, newPassword);
        } while (!Validation::checkPassword(newPassword));

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
            while (!(cin >> choice) || choice < 1 || choice > 7) {
                cout << "Invalid choice. Please enter a number between 1 and 7: ";
            }

            switch (choice) {
            case 1:
                depositClient();
                break;
            case 2:
                withdrawClient();
                break;
            case 3:
                client->checkBalance();
                break;
            case 4:
                transferAmount();
                break;
            case 5:
                client->Display();
                break;
            case 7:
                cout << "Exiting system... Goodbye!\n";
                return false;
            }

            cout << "Press [Y] to Continue or [N] to Exit: ";
            cin >> op;
            op = toupper(op);
            while (op != 'Y' && op != 'N') {
                cout << "Invalid input. Please enter 'Y' or 'N': ";
                cin >> op;
                op = toupper(op);
            }

        } while (op == 'Y');

        cout << "Exiting system... Goodbye!\n";
        return false;
    }

    static void transferAmount() {
        int recipientId, attempts;
        double amount;
        attempts = 0;
        bool validRecipient = false;

        do {
            cout << "Enter recipient id\n";
            cin >> recipientId;
            attempts++;

            if (recipientId == currentClientId) {
                cout << "Cannot transfer to yourself. Transfer canceled.\n";
            }
            else {
                Client* recipient = searchClientById(recipientId);
                if (recipient) {
                    cout << "Client found by name: " << recipient->getName() << endl;
                    validRecipient = true;
                    break;
                }
                else {
                    cout << "Recipient not found. Please try again.\n";
                }
            }
        } while (attempts < 3 && !validRecipient);

        if (!validRecipient) {
            cout << "Failed to enter a valid recipient. Transfer canceled.\n";
            return;
        }

        char confirm;
        do {
            cout << "Do you want to proceed with the transfer? (y/n): ";
            cin >> confirm;
            confirm = toupper(confirm);
            if (confirm != 'Y' && confirm != 'N') {
                cout << "Invalid input. Please enter 'Y' or 'N'.\n";
            }
        } while (confirm != 'Y' && confirm != 'N');

        if (confirm == 'Y') {
            Client* sender = searchClientById(currentClientId);
            cout << "Enter amount: ";
            cin >> amount;
            if (amount > 0) {
                if (sender->getBalance() >= amount) {
                    sender->transferTo(amount, *searchClientById(recipientId));
                    cout << "Transfer completed successfully.\n";
                    cout << "Your balance Now is -> " << sender->getBalance() << endl;
                }
                else {
                    cout << "Insufficient balance. Transfer canceled.\n";
                }
            }
            else {
                cout << "Invalid amount entered. Transfer canceled.\n";
            }
        }
        else {
            cout << "Transfer canceled.\n";
        }
    }

    static void depositClient() {
        Client* Depositor = searchClientById(currentClientId);
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        if (amount > 0) {
            Depositor->deposit(amount);
            cout << "Amount deposited successfully. New balance: " << Depositor->getBalance() << endl;
        }
        else {
            cout << "Invalid deposit amount.\n";
        }
    }

    static void withdrawClient() {
        Client* withdrawer = searchClientById(currentClientId);
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount > 0 && withdrawer->getBalance() >= amount) {
            withdrawer->withdraw(amount);
            cout << "Amount withdrawn successfully. New balance: " << withdrawer->getBalance() << endl;
        }
        else {
            cout << "Insufficient balance or invalid amount.\n";
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
};

