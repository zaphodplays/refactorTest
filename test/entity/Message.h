#pragma once
#include <ctime>
#include <string>
using std::time_t;
using std::string;

/**
 * This class represents a message entity that is sent from a user to another user.
 * 
 */
class Message {

    public:
        Message(const string sender, const string receiver, const string msg);

        /**
         * get sender name
         */
        const string& getSenderName();

        /**
         * get receiver name
         */
        const string& getReceiverName();

        /**
         * get content
         */
        const string& getContent();

        /**
         * get the message id
         */
        uint32_t getMessageID();

        /**
         * get the timestamp
         */
        time_t getTimestamp();
        

        

    private:
        // unique id for a message
        uint32_t id;

        // sender name
        string sname;

        // receiver name
        string rname;

        // message content
        string content;

        // message timestamp 
        time_t timestamp;

        //static id to generate unique id for every new message instance
        static uint32_t current_id; 

};