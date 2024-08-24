#include <iostream>
#include <string>
#include <cmath>
#include <exception>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Validation.h"
#include "Parser.h"
#include "FilesHelper.h"
#include "FileManager.h"
#include "Screens.h"

using namespace std;







int main()
{
    Admin* admin = Admin::getInstance(); 
    FileManager f;
    f.getAllClients();
    f.getAllEmployees();
    f.getAllAdmins();
    Screens::runApp();
    return 0;


}
