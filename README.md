# SpamCallDetector
The program is a comprehensive Spam Caller Detector, written in C++, a high-level programming language known for its efficiency and control over system resources. The primary purpose of this program is to provide users with a robust tool to identify and manage spam phone calls.

The program operates by checking incoming phone numbers against a predefined logic to determine if they are spam. This logic can be customized according to the user's needs. Currently, the program considers all phone numbers starting with '9' as spam, but this can be modified.

One of the key features of this program is its Blacklist/Whitelist system. Users can add numbers to a blacklist, which are always considered as spam, or a whitelist, which are never considered as spam. These lists are stored in text files and loaded each time the program runs.

The program also provides options for users to store or delete identified spam numbers. If a number is identified as spam, users can choose to store it in a text file for future reference or delete it if it's already stored.

In addition to these features, the program includes a user-friendly menu system that allows users to easily navigate through the different options. This includes checking if a number is spam, adding or removing numbers from the blacklist or whitelist, and exiting the program.

Overall, this Spam Caller Detector serves as a practical tool for managing and controlling spam calls effectively. Its modular design and use of standard C++ libraries make it highly adaptable for future enhancements and integrations.
