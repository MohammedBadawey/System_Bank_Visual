#pragma once
#include "AdminManager.h"
#include "FileManager.h"




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
    }

    static void loginOptions() {
        cout << "\t\t\t\t\t   Select login option:\n";
        cout << "\t\t\t\t\t   1. Client\n";
        cout << "\t\t\t\t\t   2. Employee\n";
        cout << "\t\t\t\t\t   3. Admin\n";
        cout << "\t\t\t\t\t   4. Exit\n";
    }

    // d. static int loginAs()
    static int loginAs() {
        int option;
        loginOptions();
        cout << "\t\t\t\t\tEnter your choice: ";
        while (!(cin >> option) || option < 1 || option > 4) {
            cout << "Invalid choice. Please enter a number between 1 and 4: ";
            cin >> option;
            cout << endl;
        }
        return option;
    }

    // e. static void invalid(int c)
    static void invalid(int c) {
        cout << "Invalid choice (" << c << "). Please try again.\n";
    }

    // f. static void logout()
    static void logout() {
        cout << "Logging out... Goodbye!\n";
    }

    // g. static void loginScreen(int c)
    static void loginScreen(int c) {
        int id;
        string password;
        switch (c) {
        case 1: {
            cout << "Client Login:\n";
            cout << "Enter Client ID: ";
            cin >> id;
            cout << "Enter Password: ";
            cin >> password;
            Client* client = ClientManager::login(id, password);
            if (client) {
                ClientManager::clientOptions(client);
            }
            else {
                invalid(c);
            }
            break;
        }
        case 2: {
            cout << "Employee Login:\n";
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Password: ";
            cin >> password;
            Employee* employee = EmployeeManager::login(id, password);
            if (employee) {
                EmployeeManager::employeeOptions(employee);
            }
            else {
                invalid(c);
            }
            break;
        }
        case 3: {
            cout << "Admin Login:\n";
            cout << "Enter Admin ID: ";
            cin >> id;
            cout << "Enter Password: ";
            cin >> password;
            Admin* admin = AdminManager::login(id, password);
            if (admin) {
                AdminManager::adminOptions();
            }
            else {
                invalid(c);
            }
            break;
        }
        case 4:
            logout();
            break;
        default:
            invalid(c);
            break;
        }
    }

    // h. static void runApp()
    static void runApp() {
        FileManager* f = new FileManager();
        f->getAllClients();
        f->getAllEmployees();
        f->getAllAdmins();

        int choice;
        do {
            welcome();
            choice = loginAs();
            loginScreen(choice);
        } while (choice != 4);
    }
};