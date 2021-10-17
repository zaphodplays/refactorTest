#pragma once
#include <string>
using std::string;
/**
 * This is the result object sent back from the service to the command layer
 * It contains a status of success or failure
 * It also contains a detailed message for displaying to the user
 **/
class Result
{
    public:
        Result(bool status, string msg){success = status; message = msg;}

        bool isSuccess(){return success;}
        string getMessage() {return message;}

    private:
        // success or failure of a command
        bool success;

        // a detailed message about the result of a command
        string message;
};