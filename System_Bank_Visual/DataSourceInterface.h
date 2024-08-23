#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;
class DataSourceInterface {
public:
    virtual void addClient(Client* client) = 0;
    virtual void addEmployee(Employee* employee) = 0;
    virtual void addAdmin(Admin* admin) = 0;

    virtual void getAllClients() const = 0;
    virtual void getAllEmployees() const = 0;
    virtual void getAllAdmins() const = 0;

    virtual void removeAllClients() = 0;
    virtual void removeAllEmployees() = 0;
    virtual void removeAllAdmins() = 0;

    virtual ~DataSourceInterface() {}
};
