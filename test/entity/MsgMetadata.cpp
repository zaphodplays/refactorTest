#include "MsgMetadata.h"


MsgMetadata::MsgMetadata(uint32_t &id, uint32_t &senderID, uint32_t &receiverID, time_t &timestamp)
{
    this->id = id;
    this->senderID = senderID;
    this->receiverID = receiverID;
    this->timestamp = timestamp;
}

uint32_t MsgMetadata::getID()
{
    return id;
}

uint32_t MsgMetadata::getSenderID()
{
    return senderID;
}

uint32_t MsgMetadata::getReceiverID()
{
    return receiverID;
}

time_t MsgMetadata::getTimestamp()
{
    return timestamp;
}