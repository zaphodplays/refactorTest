#include "GetAllMessagesBySendersCommand.h"
#include <iostream>
using std::cout;
using std::endl;


const string GetAllMessagesBySendersCommand::description()
{
    string desc = "4. get messages report grouped by sender";
    return desc;
}

bool GetAllMessagesBySendersCommand::run()
{
    
    map<uint32_t, AMessageService::SET_METADATA_BY_RECEIVER_AND_TIME> msgMap = AMessageService::getInstance().getAllMessagesGroupedBySenderID();
    map<uint32_t, AMessageService::SET_METADATA_BY_RECEIVER_AND_TIME>::iterator mitor = msgMap.begin();

    cout << endl << "===== BEGIN MESSAGES =====" << endl;
    while(mitor != msgMap.end())
    {
        uint32_t senderID = mitor->first;
        AMessageService::SET_METADATA_BY_RECEIVER_AND_TIME sset = mitor->second;
        int num = sset.size();
        if(num > 0)
        {
           AMessageService::SET_METADATA_BY_RECEIVER_AND_TIME::iterator sitor = sset.begin();
           cout << "sender "<< senderID << "(" << num <<" messages)"<<endl;
           while(sitor != sset.end())
           {
               /**
                * sender 1 (3 messages):
                *timestamp, recipient 1
                * */
                const time_t t = (*sitor)->getTimestamp();
                string timeString = std::asctime(std::localtime( &t) );
                
                cout << timeString.substr(0, timeString.length()-1) << ", receiver "<<(*sitor)->getReceiverID()<< endl;
                sitor++;
           } 
           cout<<endl;
        }

        mitor++;
    } 
    cout << endl << "===== END MESSAGES =====" << endl;

    return false;
}