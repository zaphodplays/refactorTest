#include "GetReceiverMessagesCommand.h"
#include <iostream>
using std::cout;
using std::endl;


const string GetReceiverMessagesCommand::description()
{
    string desc = "3. Receive All Messages For User";
    return desc;
}

bool GetReceiverMessagesCommand::run()
{
    std::string user;
    UserInputUtil::handleUserInput("Enter name of user to receive all messages for: \n", user);
   
   
    Result userResult = UserService::getInstance().doesUserExist(user);

    if (userResult.isSuccess())
    {
        
        shared_ptr<AMessageService::SET_AMESSAGES_BY_SENDER_AND_TIME> msgSet = AMessageService::getInstance().getMessagesForReceiver(user);
        AMessageService::SET_AMESSAGES_BY_SENDER_AND_TIME::iterator mitor = msgSet->begin();
        cout << endl << "===== BEGIN MESSAGES =====" << endl;
        int num = 1;
        while(mitor != msgSet->end())
        {
            cout << "Message " <<  num <<endl;
            cout << "From: " << (*mitor)->getSenderName() << endl;
            cout << "Content: " << (*mitor)->getContent() << endl << endl;
            //mitor = msgSet.erase(mitor);
            mitor++;num++;
        }
        msgSet->clear();
        
        cout << endl << "===== END MESSAGES =====" << endl;
       

    } else
        cout <<userResult.getMessage() << endl;
        
    return false;
}