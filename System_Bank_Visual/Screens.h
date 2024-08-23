#pragma once
#include <iostream>
#include <string>
#include "ClientManager.h"
#include "AdminManager.h"


using namespace std;

class Screens {
public:

    static void bankName() {
        cout << "\t\t\t\t ****************************************\n";
        cout << "\t\t\t\t*             Mohammed Bank              *\n";
        cout << "\t\t\t\t ****************************************\n";
    }

    static void welcome() {
        cout << "\t\t\t\t\tWelcome to Mohammed Bank!\n";
        cout << "\t\t\t\t   Please choose an option to proceed.\n";
    }

    static void loginOptions() {
        cout << "\t\t\t\t\t1 - Login as Client\n";
        cout << "\t\t\t\t\t2 - Login as Employee\n";
        cout << "\t\t\t\t\t3 - Login as Admin\n";
        cout << "\t\t\t\t\t4 - Exit\n";
    }

    static int loginAs() {
        int choice;
        cout << "\t\t\t\t\tEnter your choice: ";
        cin >> choice;
        return choice;
    }

    static void invalid(int c) {
        switch (c) {
        case 1:
            cout << "Invalid login attempt. Please try again.\n";
            break;
        case 2:
            cout << "Invalid choice. Please enter a valid option.\n";
            break;
        default:
            cout << "Unknown error occurred.\n";
            break;
        }
    }

    static void logout() {
        cout << "You have been logged out successfully.\n";
    }

    static void loginScreen(int c) {
        switch (c) {
        case 1:
            cout << "Client Login:\n";
            break;
        case 2:
            cout << "Employee Login:\n";
            break;
        case 3:
            { cout << "Admin Login:\n";
            int id;
            string password;
            cout << "enter id\n";
            cin >> id;
            cout << "enter pass\n";
            cin >> password;
            AdminManager::login(id,password);
            break;
        }
        default:
            cout << "Invalid option for login.\n";
            break;
        }
    }

    static void runApp() {
        int choice;
        bankName();
        welcome();

        do {
            loginOptions();
            choice = loginAs();
            if (choice == 4) {
                cout << "Exiting system... Goodbye!\n";
                break;
            }
            if (choice >= 1 && choice <= 3) {
                loginScreen(choice);
            }
            else {
                invalid(2);
            }
        } while (true);
    }

};