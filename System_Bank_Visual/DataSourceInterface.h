#pragma once

using namespace std;


class Client;   // Forward declaration
class Employee; // Forward declaration
class Admin;    // Forward declaration

class DataSourceInterface {
public:
    virtual void addClient(Client* client) = 0;
    virtual void addEmployee(Employee* employee) = 0;
    virtual void addAdmin(Admin* admin) = 0;

    virtual void getAllClients()  = 0;
    virtual void getAllEmployees()  = 0;
    virtual void getAllAdmins()  = 0;

    virtual void removeAllClients() = 0;
    virtual void removeAllEmployees() = 0;
    virtual void removeAllAdmins() = 0;

    virtual ~DataSourceInterface() {}
};
