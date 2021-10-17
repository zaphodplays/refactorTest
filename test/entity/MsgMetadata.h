#pragma once
#include <ctime>
#include <string>
#include "AMessage.h"
using std::time_t;
using std::string;

/**
 * This class is pure metadata about the message. 
 * It contains data about message - message id, senderID, receiverID, timestamp
 * It does not contain user names or message content
 */
class MsgMetadata 
{
    public:

        MsgMetadata(uint32_t &id, uint32_t &senderID, uint32_t &receiverID, time_t &timestamp);

        uint32_t getID();

        uint32_t getSenderID();

        uint32_t getReceiverID();

        time_t getTimestamp();
        
    private:

        // unique id for user
        uint32_t id;

        /// user id of sender
        uint32_t senderID;

        // user id of receiver
        uint32_t receiverID;

        // timestamp
        time_t timestamp;        
};