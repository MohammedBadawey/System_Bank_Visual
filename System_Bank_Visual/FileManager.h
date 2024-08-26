#pragma once
#include "DataSourceInterface.h"
#include "FilesHelper.h"
using namespace std;

class FileManager : public DataSourceInterface {
public:
    FileManager() {};
    void addClient(Client* client)  {
        FilesHelper::saveClient(client);
    }

    void addEmployee(Employee* employee)  {
        FilesHelper::saveEmployee(employee);
    }

    void addAdmin(Admin* admin)  {
        FilesHelper::saveAdmin(admin);
    }

    void getAllClients() {
        FilesHelper::getClients();
    }

    void getAllEmployees()  {
        FilesHelper::getEmployees();
    }

    void getAllAdmins()  {
        FilesHelper::getAdmins();
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
