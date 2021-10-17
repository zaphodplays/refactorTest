#include "UserService.h"


Result* UserService::USER_ADD_SUCCESS = UserService::initResults(true, "user registered successfully");
Result* UserService::USER_EXISTS_SUCCESS = UserService::initResults(true, "user exists");
Result* UserService::USER_EXISTS_FALSE = UserService::initResults(false, "ERROR: User doesn't exist!");
Result* UserService::USER_ADD_EXISTS_FAILURE = UserService::initResults(false, "ERROR: User already exists!");
Result* UserService::USER_ADD_BAD_NAME_FAILURE = UserService::initResults(true, "unacceptable format for user name");
Result* UserService::USER_CHECK_NOT_EXIST_FAILURE = UserService::initResults(false, "this user doesn't exist yet");




UserService::~UserService()
{
    userNameMap.clear();
    names.clear();
}

bool UserService::exists(const string &name)
{
    return (names.find(name) != names.end());

}

const Result& UserService::doesUserExist(const string &name)
{
    if(name.empty() || !exists(name))
        return *USER_EXISTS_FALSE;
    
    return *USER_EXISTS_SUCCESS;  
    
}

const Result& UserService::addUser(const string &name)
{
    if(name.empty())
        return *USER_ADD_BAD_NAME_FAILURE;
    if(exists(name))
        return *USER_ADD_EXISTS_FAILURE;
    
    userNameMap[name] = make_shared<User>(name);
    names.insert(name);
    return *USER_ADD_SUCCESS;
       
}

shared_ptr<User> UserService::getUserByName(const string &name)
{
    map<string, shared_ptr<User> >::iterator itor = userNameMap.find(name);
    if(itor != userNameMap.end())
        return itor->second;
    return nullptr;
}

/********************************************************************************/
/**********************************TESTS*****************************************/

void UserService::runTests()
{   
    std::cout<<"*************STARTING USER TESTS***********************"<<std::endl;
    
    testCreateUsers();
    testDoesUserExist();
    clearTestUsers();

    std::cout<<"*************FINISHED USER TESTS***********************"<<std::endl;
}

void UserService::testCreateUsers()
{
    //lets create 10000 users
    uint32_t num = 10000;
    string prefix = "user";
    for(uint32_t i = 0; i < num; i++)
    {
        string name = prefix + std::to_string(i);
        addUser(name);
    }
    assert(userNameMap.size() == num);
    assert(userNameMap.find("user0") != userNameMap.end());

    //lets test by trying to add a user thats already registered
    Result result = addUser("user0");
    assert( (result.isSuccess() == false) && (result.getMessage() == USER_ADD_EXISTS_FAILURE->getMessage()) );
    std::cout<<"created users"<<std::endl;
}

void UserService::testDoesUserExist()
{
    uint32_t num = 10000;
    string prefix = "user";
    string name = prefix + std::to_string(rand()%num);
    Result result = doesUserExist(name);
    assert(result.isSuccess() == true && result.getMessage() == USER_EXISTS_SUCCESS->getMessage());

    
    //lets test a user thats not there
    string dummyName = "dummy";
    Result dummyResult = doesUserExist(dummyName);
    assert(dummyResult.isSuccess() == false);
    assert(dummyResult.getMessage() == USER_EXISTS_FALSE->getMessage());    
    std::cout<<"tested creating users"<<std::endl;
}

void UserService::clearTestUsers()
{
    names.clear();
    userNameMap.clear();
    std::cout<<"destroyed test users"<<std::endl;
}