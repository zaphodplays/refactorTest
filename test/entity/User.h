#pragma once
#include <string>
using std::string;

/**
 * This class represents a User entity. 
 * A User object has a unique id and a name. 
 */
class User
{
    string name;
    uint32_t id;
    static uint32_t current_id; 
   
    public:
        User(string name);
        uint32_t getUserID();
        const string& getName();

};