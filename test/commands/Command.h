#pragma once
#include <string>
using std::string;

/**
 * This is the Command interface that defines the API for menu display and menu based 
 * functionality. All child classes that extend from Command can implement these virtual 
 * methods to define different menu displays and menu functionalities.
 */
class Command 
{
    public :

        /**
         * This method returns the diplay for a menu item. 
         * The child Command class will override it for a specific menu item.
         */
        virtual const string description() = 0;

        /**
         * This method will be used by the child Command classes to implement 
         * the different menu based functionalaties that can be executed. 
         */
        virtual bool run() = 0;

        /**
         * virtual destructor for the parent Command class. 
         */
        virtual ~Command() = default;


};