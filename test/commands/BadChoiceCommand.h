#pragma once
#include <iostream>
#include "Command.h"

/**
 * This class extends the Command interface to represent a bad choice entered by user
 */
class BadChoiceCommand : public Command 
{
    public:

    const string description();

    bool run();
};