#include <iostream>
#include <string>
#include <cmath>
#include <exception>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Validation.h"
#include "Functions.h"
#include "Parser.h"

using namespace std;







int main()
{
    Admin* admin = Admin::getInstance();
    Functions::OpenSystem();
    return 0;


}
