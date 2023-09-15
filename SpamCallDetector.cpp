/*
By: Caesar R. Watts-Hall
Date: June 08, 2023
*/

#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

set<string> blacklist;
set<string> whitelist;

void loadLists() {
    ifstream file;
    string line;

    file.open("blacklist.txt");
    while (getline(file, line)) {
        blacklist.insert(line);
    }
    file.close();

    file.open("whitelist.txt");
    while (getline(file, line)) {
        whitelist.insert(line);
    }
    file.close();
}

bool isSpamNumber(string phoneNumber) {
    if (whitelist.count(phoneNumber) > 0) {
        return false;
    }
    if (blacklist.count(phoneNumber) > 0) {
        return true;
    }

    return phoneNumber[0] == '9';
}

void addToBlacklist(string phoneNumber) {
    ofstream file;
    file.open("blacklist.txt", ios::app);
    file << phoneNumber << endl;
    file.close();
}

void removeFromBlacklist(string phoneNumber) {
    ifstream file;
    file.open("blacklist.txt");
    ofstream temp;
    temp.open("temp.txt");
    string line;
    while (getline(file, line)) {
        if (line != phoneNumber) {
            temp << line << endl;
        }
    }
    temp.close();
    file.close();
    remove("blacklist.txt");
    rename("temp.txt", "blacklist.txt");
}

void addToWhitelist(string phoneNumber) {
    ofstream file;
    file.open("whitelist.txt", ios::app);
    file << phoneNumber << endl;
    file.close();
}

void removeFromWhitelist(string phoneNumber) {
    ifstream file;
    file.open("whitelist.txt");
    ofstream temp;
    temp.open("temp.txt");
    string line;
    while (getline(file, line)) {
        if (line != phoneNumber) {
            temp << line << endl;
        }
    }
    temp.close();
    file.close();
    remove("whitelist.txt");
    rename("temp.txt", "whitelist.txt");
}

void printMenu() {
   cout << "Welcome to the Spam Caller Detector! Please select an option:" << endl;
   cout << "[1] Spam Number Checker" << endl;
   cout << "[2] Caller ID" << endl;
   cout << "[3] Blacklist/Whitelist System" << endl;
   cout << "[4] Reporting System" << endl;
   cout << "[5] Exit/End Program" << endl;
}

int main() {
   loadLists();

   while (true) {
       printMenu();
       int choice;
       cin >> choice;

       if (choice == 1) {
           string phoneNumber;
           cout << "Enter phone number: ";
           cin >> phoneNumber;

           if (isSpamNumber(phoneNumber)) {
               cout << "The phone number is a spam number." << endl;
           } else {
               cout << "The phone number is not a spam number." << endl;
           }
       } else if (choice == 2) {
           // Caller ID
           // This feature would likely require integration with your phone system or service provider,
           // which is beyond the scope of a simple C++ program.
       } else if (choice == 3) {
           // Blacklist/Whitelist System
           // Rest of the code...
       } else if (choice == 4) {
           // Reporting System
           // This feature would likely require integration with your phone system or service provider,
           // which is beyond the scope of a simple C++ program.
       } else if (choice == 5) {
           // Exit/End Program
           cout << "Thank you for using this system. Have a nice day!" << endl;
           break;
       } else {
           cout << "Invalid choice. Please try again." << endl;
       }
   }

   return 0;
}
