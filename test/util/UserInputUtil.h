#pragma once
#include <iostream>
#include <string>

using std::string;
using std::endl;
using std::cout;
using std::cin;

/**
 * Utility class containing methods for display and user interaction
 */
class UserInputUtil 
{
    public:
        
        /**
         * used for UI interaction with user
         * @params: message to be displayed
         * @params: in, reference that stores user input
         */
        static void handleUserInput(const string message, string &in)
        {
            cout << message << endl;
            std::getline(cin, in);
            cout << endl;    
        }
};