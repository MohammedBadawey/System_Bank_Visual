#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "Person.h"
#include "Validation.h"
#include "Client.h"
using namespace std;

class Employee : public Person
{

    // att
protected:
    double salary;
    static int newEmployeeId;
    static vector<Client*> clientList;

    // con
public:
    Employee()
    {
        salary = 0.0;
        id = newEmployeeId++;
    }
    Employee(string name, int id, string password, double salary) :Person(name, id, password)
    {
        setSalary(salary);

    }
    //setter
    void setSalary(double salary)
    {
        while (!Validation::checkSalary(salary)) {
            cin >> salary;
        }
        this->salary = salary;
    }
    // getter
    double getSalary()
    {
        return salary;
    }
    static int getNewEmployeeId() { return newEmployeeId; }

    // methods
    const void Display()
    {
        Person::Display();
        cout << "Salary -> " << salary << endl;
    }

    void addClient(Client& client) {
        clientList.push_back(&client);
    }

    Client* searchClient(int id) {
        for (Client* client : clientList) {
            if (client->getId() == id) {
                return client;
            }
        }
        return nullptr;
    }

    void listClient() {
        if (clientList.empty()) {
            cout << "No clients available." << endl;
            return;
        }

        for (Client* client : clientList) {
            client->Display();
            cout << "=============" << endl;
        }
    }

    void editClient(int id, string name, string password, double balance) {
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
    }

    void login()  {
        cout << "Employee " << name << " logged in." << endl;
    }

    void logout() {
        cout << "Employee " << name << " logged out." << endl;
    }

};

