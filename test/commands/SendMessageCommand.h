#pragma once
#include "Command.h"
#include "UserService.h"
#include "AMessageService.h"
#include "UserInputUtil.h"

/**
 * This class extends the Command interface to implement the 
 * menu item - "Send Message"
 */
class SendMessageCommand : public Command
{
    public:

       virtual const string description() override;

        virtual bool run() override;
};