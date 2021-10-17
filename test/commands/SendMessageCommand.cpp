#include "SendMessageCommand.h"
#include <iostream>
using std::cout;
using std::endl;

const string SendMessageCommand::description()
{
    string desc = "2. Send Message";
    return desc;
}

bool SendMessageCommand::run()
{
    
    
	std::string sender;
	UserInputUtil::handleUserInput("From: ", sender);
	
	Result result1 = UserService::getInstance().doesUserExist(sender);
	if (!result1.isSuccess())
		cout <<result1.getMessage() << endl;
	else {
		
		std::string receiver;
		UserInputUtil::handleUserInput("To: ", receiver);

		Result result2 = UserService::getInstance().doesUserExist(receiver);
		if (!result2.isSuccess())
			cout <<result2.getMessage() << endl;
		else {
			
			std::string msg;
			UserInputUtil::handleUserInput("Message: ", msg);
			
			Result result = AMessageService::getInstance().createAMessage(sender, receiver, msg);
			cout<<result.getMessage()<<endl;
		}
	}

	return false;
}