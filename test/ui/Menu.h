#pragma once
#include "UserInputUtil.h"
#include "AddUserCommand.h"
#include "SendMessageCommand.h"
#include "GetReceiverMessagesCommand.h"
#include "GetAllMessagesBySendersCommand.h"
#include "BadChoiceCommand.h"
#include "QuitCommand.h"
#include <vector>
#include <map>
#include <memory>

using std::vector;
using std::map;


/**
 * This is the class where the UI is displayed.
 * This class is also responsible for invoking the appropriate command based on user input.
 */
class Menu
{
    public:
        Menu();
        ~Menu();

        /**
         * This is where the interactive UI loop is started.
         */
        void execute();

    private:

        /**
         * Here the menu UI is displayed and the user choice is gathered.
         * The appropriate command is invoked based on user choice.
         * @returns: returns true if user selects the 'Quit' option
         */
        bool processInput();

        /**
         * builds and stores the menu string using descriptions from different menu commands 
         * for menu display
         */
        void buildMenuString();

       

        /**
         * this is a map that indexes Command object pointers 
         * key: user selected menu number option
         * value : Command object pointer for appropriate functional Command
         */
        map<string, Command*> commandsMap;

        /**
         * this stores the menu string constructed at initialization from different commands
         */
        string menuString;
};