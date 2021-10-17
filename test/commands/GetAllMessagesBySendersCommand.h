#pragma once
#include "Command.h"
#include "UserService.h"
#include "AMessageService.h"


/**
 * This class extends the Command interface to implement the 
 * menu item - "get messages for receiver"
 */
class GetAllMessagesBySendersCommand : public Command
{
    public:

        virtual const string description() override;

        virtual bool run() override;
    
};