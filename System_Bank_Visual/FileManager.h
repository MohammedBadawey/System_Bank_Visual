#pragma once
#include "DataSourceInterface.h"
#include "FilesHelper.h"

class FileManager : public DataSourceInterface {
public:
    void addClient(Client* client)  {
        FilesHelper::saveClient(client);
    }

    void addEmployee(Employee* employee)  {
        FilesHelper::saveEmployee(employee);
    }

    void addAdmin(Admin* admin) override {
        FilesHelper::saveAdmin(admin);
    }

    void getAllClients(std::vector<Client*>& clients)  {
        FilesHelper::getClients();
        clients = FilesHelper::clients;
    }

    void getAllEmployees(std::vector<Employee*>& employees)  {
        FilesHelper::getEmployees();
        employees = FilesHelper::employees;
    }

    void getAllAdmins(std::vector<Admin*>& admins)  {
        FilesHelper::getAdmins();
        admins = FilesHelper::admins;
    }

    void removeAllClients()  {
        FilesHelper::clearFile("clientData.txt", "lastClientId.txt");
    }

    void removeAllEmployees()  {
        FilesHelper::clearFile("employeeData.txt", "lastEmployeeId.txt");
    }

    void removeAllAdmins()  {
        FilesHelper::clearFile("adminData.txt", "lastAdminId.txt");
    }
};
