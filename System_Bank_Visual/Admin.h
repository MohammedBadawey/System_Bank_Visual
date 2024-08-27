#pragma once
#include "Employee.h"






using namespace std;
class Admin : public Employee
{
private:
    
    static Admin* instance;
    Admin(string name, int id, string password, double salary)
        : Employee(name, id, password, salary) {}

public:
    static Admin* getInstance(string name = "Mohammed", int id = 1, string password = "Mohammed123", double salary = 9000) {
        if (instance == nullptr)
        {
            instance = new Admin(name, id, password, salary);
        }
        return instance;

    }

    /*const void Display()
    {
        Employee::Display();
    }*/

    //void addClient(Client& client) {
    //    clientList.push_back(&client);
    //}

    /*Client* searchClient(int id) {
        for (Client* client : clientList) {
            if (client->getId() == id) {
                return client;
            }
        }
        return nullptr;
    }*/

    /*void listClient() const {
        if (clientList.empty()) {
            cout << "No clients available." << endl;
            return;
        }

        for (Client* client : clientList) {
            client->Display();
            cout << "------" << endl;
        }
    }*/

    /*void editClient(int id, string name, string password, double balance) {
        Client* client = searchClient(id);
        if (client) {
            client->setName(name);
            client->setPassword(password);
            client->setBalance(balance);
            cout << "Client updated successfully." << endl;
        }
        else {
            cout << "Client not found." << endl;
        }
    }*/

    void addEmployee(Employee& employee) {
        employeeList.push_back(&employee);
    }

    Employee* searchEmployee(int id) {
        for (Employee* employee : employeeList) {
            if (employee->getId() == id) {
                return employee;
            }
        }
        return nullptr;
    }

    void editEmployee(int id, string name, string password, double salary) {
        Employee* employee = searchEmployee(id);
        if (employee) {
            employee->setName(name);
            employee->setPassword(password);
            employee->setSalary(salary);
            cout << "Employee updated successfully." << endl;
        }
        else {
            cout << "Employee not found." << endl;
        }
    }

    void listEmployee() const {
        if (employeeList.empty()) {
            cout << "No employees available." << endl;
            return;
        }

        for (Employee* employee : employeeList) {
            employee->Display();
            cout << "------" << endl;
        }
    }

};
