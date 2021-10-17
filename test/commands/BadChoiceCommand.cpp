#include "BadChoiceCommand.h"


const string BadChoiceCommand::description() 
{
    return "";
}

bool BadChoiceCommand::run()
{
    std::cout<<"Invalid Option Selected"<<std::endl;
    return false;
}