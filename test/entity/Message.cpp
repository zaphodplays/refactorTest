#include "Message.h"

uint32_t Message::current_id = 0;

Message::Message(const string &sender, const string &receiver, const string &msg)
{
    this->id = ++current_id;
    this->sname = sender;
    this->rname = receiver;
    this->content = msg;
    this->timestamp = std::time(nullptr);
    
}

const string& Message::getSenderName()
{
    return sname;
}

const string& Message::getReceiverName()
{
    return rname;
}

uint32_t Message::getMessageID()
{
    return id;
}

time_t Message::getTimestamp()
{
    return timestamp;
}

const string& Message::getContent()
{
    return content;
}

