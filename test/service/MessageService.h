#pragma once
#include "Message.h"
#include "MsgMetadata.h"
#include "User.h"
#include "UserService.h"
#include "Result.h"
#include <memory>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using std::shared_ptr;
using std::make_shared;
using std::vector;
using std::map;
using std::set;

/**
 * The MessageService is the managing class which manages the datastructures
 * holding the messages in system.
 * Its responsibilities include :
 * 1. creating new messages and storing them in the messageMaps.
 * 2. sending results for the query : get all messages for a receiver
 * 3. sending results for the query : get all message metadata, grouped by sender, sorted by receiver, timestamp
 * 
 */
class MessageService {

    /**
     * This structure is used as the custom comparator for comparing between
     * two MsgMetadata objects. It sorts the objects based on receiver id and msg timestamp. 
     */
    struct metadata_receiver_timestamp_comparator;

    /**
     * This structure is used as the custom comparator for comparing between
     * two Message objects. It sorts the objects based on sender name and msg timestamp. 
     */
    struct message_sender_timestamp_comparator;


    public:
        
        // we define this type as set of MsgMetadata pointers based on custom comparator
        typedef set<shared_ptr<MsgMetadata> , metadata_receiver_timestamp_comparator> SET_METADATA_BY_RECEIVER_AND_TIME; 

        // we define this type as set of Message pointers based on custom comparator
        typedef set<shared_ptr<Message> , message_sender_timestamp_comparator> SET_AMESSAGES_BY_SENDER_AND_TIME;

        /**
         * creates a new Message and MsgMetadata object
         * The Message object pointer is stored in receiverMap based on the receiver name key
         * The MsgMetadata object pointer is stored in the senderMap based on the sender name key
         * @param senderName 
         * @param receiverName
         * @param text content of the message
         * @return Result object containing the status(success/fail) and any success/error message
         */
        const Result& createMessage(string senderName, string receiverName, const string text);

        /**
         * returns a pointer to the sorted set of messages for a receiver
         * @param name receiver name
         * @return shared_ptr<SET_AMESSAGES_BY_SENDER_AND_TIME> 
         */
        shared_ptr<SET_AMESSAGES_BY_SENDER_AND_TIME> getMessagesForReceiver(string name);
        

        /**
         * returns a map of MsgMetadata objects
         * key is  sender name
         * value is set of MsgMetadata objects sorted by custom comparator(receiver name, timestamp) 
         * @return map<string, MessageService::SET_METADATA_BY_RECEIVER_AND_TIME>
         */
        map<uint32_t, MessageService::SET_METADATA_BY_RECEIVER_AND_TIME> &getAllMessagesGroupedBySenderID();

        /**
         * provides a single point of access to get the singleton instance of this class
         */
        static MessageService &getInstance()
        {
            static MessageService* instance = new MessageService();
            return *instance;
        }

        // a static result object used to send a success status 
        static Result* MSG_SENT_SUCCESS;

        virtual ~MessageService();

        /**
         * This method can be invoked to run tests on MessageService
         */
        void runTests();

    private:
        /**
         * MessageService constructor is private to restrict the number of instances 
         * of this class
         */
        MessageService() { }
        
        /**
         * creates a test setup by creating dummy users and sending test messages
         */
        void testSetup();

        /**
         * destroys the test setup
         */
        void clearTestSetup();

        /**
         * tests getting messages by test users as receiver
         */
        void testGetMessagesForReceiver();
        
        /**
         * comparator to sort message metadata by receiver and timestamp
         **/
        struct metadata_receiver_timestamp_comparator{
            bool operator() (const shared_ptr<MsgMetadata> & lhs, const shared_ptr<MsgMetadata> & rhs) const
            {
                if(lhs->getReceiverID() < rhs->getReceiverID())
                    return true;
                else if( lhs->getReceiverID() > rhs->getReceiverID())
                    return false;
                return lhs->getTimestamp() < rhs->getTimestamp();
            }
        };

        /**
         * comparator to sort messages by sender and timestamp
         **/
        struct message_sender_timestamp_comparator {
            bool operator() (const shared_ptr<Message> & lhs, const shared_ptr<Message> & rhs) const
            {
                if(lhs->getSenderName() < rhs->getSenderName())
                    return true;
                else if( lhs->getSenderName() > rhs->getSenderName())
                    return false;
                return lhs->getTimestamp() < rhs->getTimestamp();
            }
        };
        
        /**
         * map to store a set of MsgMetadata objects indexed by senderID
         * key: senderID
         * value : set<MsgMetadata> with custom comparator to sort MsgMetadata objects 
         * by receiverID and timestamp
         */
        map<uint32_t, SET_METADATA_BY_RECEIVER_AND_TIME> senderMessagesMap;


        /**
         * map to store a set of Message objects indexed by receiver name
         * key: receiver name
         * value : shared_ptr<SET_AMESSAGES_BY_SENDER_AND_TIME> ,  uses 
         * a custom comparator to sort Messages by sender and timestamp.
         */
        map<string, shared_ptr<SET_AMESSAGES_BY_SENDER_AND_TIME> > receiverMessagesMap;
        

};