#pragma once
#include "Command.h"

/**
 * This class extends the Command interface to implement the 
 * menu item - "quit"
 */
class QuitCommand : public Command
{
    public:

        virtual const string description() override;

        virtual bool run() override;

        
};

    