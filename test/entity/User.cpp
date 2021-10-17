#include "User.h"

uint32_t User::current_id = 0;

User::User(string name)
{
    this->id = ++current_id;
    this->name = name;
}

const string& User::getName()
{
    return name;
}

uint32_t User::getUserID()
{
    return id;
}