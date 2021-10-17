#include "Menu.h"
#include <iostream>
using std::cout;
using std::endl;


Menu::Menu()
{
    commandsMap["1"] = new AddUserCommand();
    commandsMap["2"] = new SendMessageCommand();
    commandsMap["3"] = new GetReceiverMessagesCommand();
    commandsMap["4"] = new GetAllMessagesBySendersCommand();
    commandsMap["5"] = new QuitCommand();

    buildMenuString();
}

Menu::~Menu()
{
    commandsMap.clear();

}

void Menu::execute()
{
    while(processInput() == false)
    {
        
    }
}


void Menu::buildMenuString()
{
    //building menu string
    menuString = "Please select an option:\n";
    for(map<string, Command*>::iterator itor = commandsMap.begin(); itor != commandsMap.end(); itor++)
    {
        menuString = menuString + itor->second->description() + "\n";
        
    }   
   
}


bool Menu::processInput()
{
    bool ret = false;
    for (int i = 0; i < 80; ++i) cout << endl;
	
   
    std::string in;
    UserInputUtil::handleUserInput(menuString, in);
    
    Command* cmd = (commandsMap.find(in) != commandsMap.end()) ? commandsMap[in] : new BadChoiceCommand();
    ret = cmd->run();
    
    
    
    std::string str;
    UserInputUtil::handleUserInput("\nEnter any key and press return to continue.....", str);
    
    
	return ret;
    
}

/**
 * This method invokes some tests on UserService and MessageService.
 */
void runTests()
{
    UserService::getInstance().runTests();
    MessageService::getInstance().runTests();
    std::string str;
    UserInputUtil::handleUserInput("\nEnter any key and press return to continue to main menu.....", str);
}

int main()
{
    //uncomment below method to run tests
    //runTests();
    Menu menu;
    menu.execute();
}




