# RefactorTest
 
Enclosed is the source for a simple command-line messaging service application.
 
In this application, it is possible to register users and then send messages between users. Currently, the 4 operations that can be performed are:

1.      Add a new user
2.      Send a user a message
3.      Receive all messages for a user
4.      Quit

We want to extend the code by creating an additional function. However, the code structure is not maintainable in its current form. So, our first request is that you improve the code, before jumping into the task of adding functionality.

To get started with the refactor, you should first familiarise yourself with the existing code. Obtain a good understanding of what the code is actually doing.

You should then refactor the code. By that, we mean adapt or even completely rewrite it from scratch. Improving the code structure is subjective but getting a sense of your coding style and structure is important to us.

Therefore, we recommend spending 2-4 hours on reading, understanding, planning and cleaning up the code. Some questions you might want to ask yourself, in terms assessing whether you’re done with refactoring:

·         Is the code readable enough such that you are happy to start extending it?
·         Is the style consistent?
·         Does the architecture adhere to best practices? E.g. SOLID design principles.
·         Do class, method & variable names make sense? Do they read well? Do they accurately describe their purpose?
·         Have appropriate data structures been used for the task at hand?
·         Are there performance implications with the additional functionality (outlined below) that need to be addressed? Of course, we are considering cases of scale – requests under large volumes of users & messages.

Once the code is in a clean state, we are now ready to start with adding new functionality.

A new operation to the system needs to be added as follows:

5.      Report all messages of all senders, sorted and grouped by their sender.

·         Order them by the recipient user id. In the case of a tie, messages should be sorted by the time they were sent.
·         With each group, report also the number of messages on that group.
·         This new operation must report all metadata of messages collected this way (not adding its text or contents) in the following column format:
       
        sender 1 (3 messages):
               timestamp, recipient 1
               timestamp, recipient 2
               timestamp, recipient 2
        sender 2 (1 message):
               timestamp, recipient 3
 
If you did the refactor well, you should be able to complete this additional functionality task within 1-2 hours.

If it takes longer than that to extend, perhaps the code structure needs some more cleaning up!
