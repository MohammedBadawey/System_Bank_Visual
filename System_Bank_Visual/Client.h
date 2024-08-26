#pragma once
#include "Person.h"

using namespace std;

class Client : public Person
{
    // att
private:
    double balance;
    // con
public:
    Client()
    {
        balance = 0.0;
    }
    Client(string name, int id, string password, double balance) : Person(name, id, password)
    {
        setBalance(balance);
    }

    //setter
    void setBalance(double balance) {
        while (!Validation::checkBalance(balance)) {
            cin >> balance;
        }
        this->balance = balance;
    }
    // getter
    const double getBalance() { return balance; }
    // methods

    void deposit(double amount)
    {
        balance += amount;
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
        }
        else
        {
            cout << "Wrong value\n";
        }
    }
    void transferTo(double amount, Client& recipient)
    {
        if (amount <= balance)
        {
            balance -= amount;
            recipient.deposit(amount);
        }
        else
        {
            cout << "Wrong value\n";
        }
    }
    const void checkBalance()
    {
        cout << "your balance is -> " << balance << endl;
    }
    const void Display()
    {
        Person::Display();
        cout << "balance-> " << balance << endl;
    }
};

