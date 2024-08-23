#pragma once
#include <iostream>
#include <string>

using namespace std;

class Screens {
public:

    static void bankName() {
        cout << "\t\t\t\t*********************************\n";
        cout << "\t\t\t *        Welcome to Mohammed Bank      *\n";
        cout << "\t\t\t\t*********************************\n";
    }

    static void welcome() {
        cout << "Welcome to Mohammed Bank!\n";
        cout << "Please choose an option to proceed.\n";
    }

    static void loginOptions() {
        cout << "1 - Login as Client\n";
        cout << "2 - Login as Employee\n";
        cout << "3 - Login as Admin\n";
        cout << "4 - Exit\n";
    }

    static int loginAs() {
        int choice;
        cout << "Enter your choice: ";
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
            cout << "Admin Login:\n";
            break;
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