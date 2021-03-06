#include "MessageService.h"

Result* MessageService::MSG_SENT_SUCCESS = new Result(true, "message successfully sent");

MessageService::~MessageService()
{
    senderMessagesMap.clear();
    receiverMessagesMap.clear();
}

const Result& MessageService::createMessage(string senderName, string receiverName, const string content)
{
    shared_ptr<Message> msg = make_shared<Message>(senderName, receiverName, content);
    uint32_t msgID = msg->getMessageID();
    uint32_t senderID = UserService::getInstance().getUserByName(senderName)->getUserID();
    uint32_t receiverID = UserService::getInstance().getUserByName(receiverName)->getUserID();
    time_t timestamp = msg->getTimestamp();
    shared_ptr<MsgMetadata> metadata = make_shared<MsgMetadata>(msgID, senderID, receiverID, timestamp);
    
    if(senderMessagesMap.find(senderID) != senderMessagesMap.end())
    {
        senderMessagesMap.find(senderID)->second.insert(metadata);    
    }
    else {
        SET_METADATA_BY_RECEIVER_AND_TIME rset;
        rset.insert(metadata);
        senderMessagesMap[senderID] = rset;    
        
    }
    

    if(receiverMessagesMap.find(receiverName) != receiverMessagesMap.end())
    {
        receiverMessagesMap.find(receiverName)->second->insert(msg);    
    }
    else {
        shared_ptr<SET_AMESSAGES_BY_SENDER_AND_TIME> sset = make_shared<SET_AMESSAGES_BY_SENDER_AND_TIME>();
        sset->insert(msg);
        receiverMessagesMap[receiverName] = sset;    
        
    }

    return *MSG_SENT_SUCCESS;
}

shared_ptr<MessageService::SET_AMESSAGES_BY_SENDER_AND_TIME> MessageService::getMessagesForReceiver(string name)
{
    
    if(receiverMessagesMap.find(name) == receiverMessagesMap.end())
    {
           
        shared_ptr<SET_AMESSAGES_BY_SENDER_AND_TIME> sset = make_shared<SET_AMESSAGES_BY_SENDER_AND_TIME>();
        receiverMessagesMap[name] = sset;    
        
    }
    return receiverMessagesMap.find(name)->second;
}
        


map<uint32_t, MessageService::SET_METADATA_BY_RECEIVER_AND_TIME> &MessageService::getAllMessagesGroupedBySenderID()
{
   return senderMessagesMap;
}

void MessageService::runTests()
{
    std::cout<<std::endl<<"*************STARTING MESSAGE TESTS***********************"<<std::endl;
    
    testSetup();
    testGetMessagesForReceiver();
    clearTestSetup();
    std::cout<<"*************FINISHED MESSAGE TESTS***********************"<<std::endl;
}

void MessageService::testSetup()
{
    std::cout<<"creating message test setup"<<std::endl;
    string prefix = "user";
    int numUsers = 10;
    vector<string> names;
    for(int i = 0; i < numUsers; i++)
    {
        string name = prefix + std::to_string(i);
        names.push_back(name);
        Result result = UserService::getInstance().addUser(name);
        //std::cout<<result.getMessage()<<std::endl;
    }
    std::cout<<"created test users"<<std::endl;
    for(uint32_t j = 0; j < names.size(); j++)
    {
        for(uint32_t k = 0; k < names.size(); k++)
        {
            if(j == k)
                continue;
            string sender = names[j];
            string receiver = names[k];
            string text = "hello" + std::to_string(j*k);
           
            Result result = createMessage(sender, receiver, text);
            assert(result.getMessage() == MSG_SENT_SUCCESS->getMessage());
            //std::cout<<"sent test message"<<std::endl;
        }
        
    }
    std::cout<<"sent test messages"<<std::endl;
    
}

void MessageService::testGetMessagesForReceiver()
{
    std::cout<<"testGetMessagesForReceiver"<<std::endl;
    string prefix = "user";
    uint32_t numUsers = 10;
     
    for(uint32_t i = 0; i < numUsers; i++)
    {
        string name = prefix + std::to_string(i);
        shared_ptr<SET_AMESSAGES_BY_SENDER_AND_TIME> sset = getMessagesForReceiver(name);
        assert(sset->size() == (numUsers - 1) ) ;
        vector<string> senders;
        for(uint32_t j = 0; j < numUsers; j++)
        {
            if(i == j) continue;
            string name = prefix + std::to_string(j);
            senders.push_back(name);
        }
        assert(senders.size() == sset->size());
        SET_AMESSAGES_BY_SENDER_AND_TIME::iterator sitor = sset->begin();
        vector<string>::iterator senditor = senders.begin();

        while(sitor != sset->end())
        {
            //checking if the senders are in sorted order
            assert( (*sitor)->getSenderName().compare(*senditor) == 0);
            senditor++; sitor++;
        }
    }
    std::cout<<"finished testing GetMessagesForReceiver"<<std::endl;
}

void MessageService::clearTestSetup()
{
    
    senderMessagesMap.clear();
    receiverMessagesMap.clear();
    std::cout<<"cleared test messages"<<std::endl;
    UserService::getInstance().clearTestUsers(); 
    std::cout<<"cleared test setup"<<std::endl;
}



