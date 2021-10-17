#pragma once
#include "Command.h"
#include "UserService.h"
#include "UserInputUtil.h"

/**
 * This class extends the Command interface to implement the Add User Menu
 */
class AddUserCommand : public Command
{
    public:

        virtual const string description() override;

        virtual bool run() override;
    
   
};
