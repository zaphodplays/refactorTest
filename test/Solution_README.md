
Keeping in mind the future extensibility of the code/design and performance/scalability under high volume usage, 
I came up with the following design :
For the interactive menu design, I used the Command interface pattern where all different Menu functionalities will be represented by different classes who all implement the Command interface. 
This gives us the advantage of seperating responsibility for the various menu items. Each different Command class impelemnets a different menu functionality and also the corresponding menu display. 

I seperated the data management layer as the service layer. 
In terms of data, I could see 2 main distinct entities for this system. 
1. A User has  userid, name. (in future can have more properties) 
2. A Message - can be created, deleted etc. (id, sender_id, receiver_id, timestamp, content)

Hence in this new design, we have 2 new entities -  User and Message

Therefore I defined 2 different Manager classes for these - 
1. UserService which manages a datastore of users.
2. MessageService which manages the datastore of messages. 




