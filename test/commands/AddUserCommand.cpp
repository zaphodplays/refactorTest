#include "AddUserCommand.h"
#include <iostream>
using std::cout;
using std::endl;

const string AddUserCommand::description()
{
    string desc = "1. Create User";
    return desc;
}
bool AddUserCommand::run()
{
    
    std::string str;
    UserInputUtil::handleUserInput("Please enter name: ", str);
    Result result = UserService::getInstance().addUser(str);
    cout<<result.getMessage()<<endl;

    return false;
    
}