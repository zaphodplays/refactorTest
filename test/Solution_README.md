
Keeping in mind the future extensibility of the code/design and performance/scalability under high volume usage, 
I came up with the following design :
For the interactive menu design, I used the Command interface pattern where all different Menu functionalities will be represented by different classes who all implement the Command interface. 
This gives us the advantage of seperating responsibility for the various menu items. Each different Command class impelemnets a different menu functionality and also the corresponding menu display. 

I seperated the data management layer as the service layer. 
In terms of data, I could see 2 main distinct entities for this system. 
1. A User has  userid, name. (in future, user can have more properties) 
2. A Message - can be created, deleted etc. (id, sender_id, receiver_id, timestamp, content)
Apart from these entities above,
we also have define extra entities -
3. MessageMetadata - this contains only the metadata information about a message - id, senderid, receiverid, timestamp
4. Result - this is a structure that is used to pass around metadata of the result of an operation back from service to command layer. 

Hence in this new design, based on the new entities -  User and Message, 

Therefore I defined 2 different Manager classes for these - 
1. UserService which manages a datastore of users.
2. MessageService which manages the datastore of messages. 

The UserService manages user data using a map with key as username and value as a pointer to the User instance. 
It also maintains a set of username strings. 
By accessing the map with the key username, fast logarithmic access to any User instance is possible, thus making this operation perforamnance safe in case of large volume users. 

Similarly, the set of user name strings will come handy in case of accessing user names in sorted order which is required for some getMessage operations later.

The MessageService manages messages sent by one user to another. 
It maintains the data as 2 maps. 
1. a map with key as senderNames and value as a pointer to a set of sorted messages(by sender and timestamp) - this datastructure gives fast access for the operation - "get messages by receiver". 

2. a map with keys as receiverNames and values as a set of MessageMetadata instances(sorted by receiverid and timestamp). 






