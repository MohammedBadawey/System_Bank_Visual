#include <iostream>
#include "FileManager.h"
#include "Screens.h"

using namespace std;



int main()
{
    Admin* admin = Admin::getInstance(); 
    FileManager f;
    Screens::runApp();
    return 0;


}
