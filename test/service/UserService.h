#pragma once
#include "User.h"
#include "Result.h"
#include <map>
#include <set>
#include <memory>
#include <iostream>
#include <assert.h>
using std::shared_ptr;
using std::make_shared;
using std::map;
using std::set;

/**
 * This is the UserService which is responsible for managing the user based operations.
 * The UserService holds a datastructure that stores the users of the system.
 * The UserService is exposed as a Singleton instance. 
 */
class UserService {

    public:

        /**
         * This is single point of access to get an instance of UserService.
         * it returns a static instance of UserService object.
         * Hence a singleton UserService is maintainted throughout the application.
         */
        static UserService &getInstance()
        {
            static UserService* instance = new UserService();
            return *instance;
        }

        /**
         * destructor for UserService
         */
        virtual ~UserService();

        /**
         * adds a user into the system
         * @param user name 
         * @returns Result object containing the bool status and result message for add user operation 
         */
        const Result& addUser(const string &name);

        /**
         * checks if a user name exists as a user in the system
         * @param name
         * @returns Result object containing bool status and a description message 
         */
        const Result& doesUserExist(const string &name);
        
        /**
         * @returns set of user name strings for users existing in the system
         */
        set<string> &getUserNames();

        /**
         * returns a pointer to a User by its name if it exists 
         */
        shared_ptr<User> getUserByName(const string &name);

        /**
         * builds test objects, invokes tests on UserService and clears the test setup 
         */
        void runTests();

        /**
         * predefined Result objects that are returned for various 
         * operations like addUser or checkUserExists
         * they can return success or failure with a detailed message
         */
        static Result* USER_ADD_SUCCESS;
        static Result* USER_EXISTS_SUCCESS;
        static Result* USER_EXISTS_FALSE;
        static Result* USER_ADD_EXISTS_FAILURE;
        static Result* USER_ADD_BAD_NAME_FAILURE;
        static Result* USER_CHECK_NOT_EXIST_FAILURE;

        //clears the test users
        void clearTestUsers();

    private:
        /**
         * private constructor for UserService
         * This ensures that noone can invoke a UserService constructor from outside
         */
        UserService() { }
        
        /**
         * checks if a user name exists as a User in the system
         * @param name
         * @returns true or false
         */
        bool exists(const string &name);

        /**
         * creates some test Users 
         * 
         */
        void testCreateUsers();

        /**
         * tests the DoesUserExist method
         */
        void testDoesUserExist();

        /**
         * This is the map indexing User object pointers by their names
         * key: user name
         * value : pointer to User
         */
        map<string, shared_ptr<User> > userNameMap;

        /**
         * a set of strings for user names
         */
        set<string> names;
        
        /**
         * method to initialize the static Result objects used for sending back results
         * of add and checkUser operations
         */
        static Result* initResults( bool status, const string &msg)
        {
            return new Result(status, msg);

        }
        
};