#include "QuitCommand.h"
#include <iostream>


const string QuitCommand::description()
{
    string desc = "5. Quit ?";
    return desc;
}
bool QuitCommand::run()
{
    std::cout<<"Quitting"<<std::endl;
    return true;
}