#include "AMessage.h"

uint32_t AMessage::current_id = 0;

AMessage::AMessage(const string sender, const string receiver, const string msg)
{
    this->id = ++current_id;
    this->sname = sender;
    this->rname = receiver;
    this->content = msg;
    this->timestamp = std::time(nullptr);
    
}

const string AMessage::getSenderName()
{
    return sname;
}

const string AMessage::getReceiverName()
{
    return rname;
}

uint32_t AMessage::getAMessageID()
{
    return id;
}

time_t AMessage::getTimestamp()
{
    return timestamp;
}

const string AMessage::getContent()
{
    return content;
}

