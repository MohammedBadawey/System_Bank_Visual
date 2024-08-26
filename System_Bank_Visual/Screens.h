#pragma once
#include "AdminManager.h"



using namespace std;

class Screens {
public:

    static void bankName() {
        cout << "\t\t\t\t **************************************** \n";
        cout << "\t\t\t\t*              Mohammed Bank             *\n";
        cout << "\t\t\t\t **************************************** \n";
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
        int id;
        string password;

        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Password: ";
        cin >> password;

        switch (c) {
        case 1: {
            Client* client = ClientManager::login(id, password);
            if (client) {
                cout << "Client logged in successfully.\n";
            }
            else {
                cout << "Client login failed.\n";
            }
        
             break;
        }
        case 2: {
            Employee* employee = EmployeeManager::login(id, password);
            if (employee) {
                cout << "Employee logged in successfully.\n";
            }
            else {
                cout << "Employee login failed.\n";
            }
            break;
        }
        case 3: {
            Admin* admin = AdminManager::login(id, password);
            if (admin) {
                cout << "Admin logged in successfully.\n";
            }
            else {
                cout << "Admin login failed.\n";
            }
            break;
        }
        default:
            cout << "Invalid option.\n";
            break;
        }
    }

    static void runApp() {
        bankName();
        welcome();

        bool running = true;

        while (running) {
            loginOptions();
            int choice = loginAs();

            if (choice == 4) {
                cout << "Exiting..." << endl;
                running = false;
            }
            else {
                loginScreen(choice);
                logout();
            }
        }
    }

};