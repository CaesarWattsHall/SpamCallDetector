/*
By: Caesar R. Watts-Hall
Date: June 08, 2023
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isSpamNumber(string phoneNumber) {
    // Function to check if the phone number is a spam number
    // This function can be modified to implement the desired logic for checking spam numbers
    return phoneNumber[0] == '9'; // Example: all phone numbers starting with 9 are considered spam
}

void storeSpamNumber(string phoneNumber) {
    // Function to store the spam number in a text file
    ofstream file;
    file.open("spamNumbers.txt", ios::app);
    file << phoneNumber << endl;
    file.close();
}

void deleteSpamNumber(string phoneNumber) {
    // Function to delete the spam number from the text file
    ifstream file;
    file.open("spamNumbers.txt");
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
    remove("spamNumbers.txt");
    rename("temp.txt", "spamNumbers.txt");
}

void readSpamNumbers() {
    // Function to read and display the spam numbers stored in the text file
    ifstream file;
    file.open("spamNumbers.txt");
    string line;
    cout << "Spam numbers:" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

int main() {
    string phoneNumber;
    cout << "Enter phone number: ";
    cin >> phoneNumber;

    if (isSpamNumber(phoneNumber)) {
        cout << "The phone number is a spam number." << endl;
        cout << "Do you want to store or delete the spam number in/from the text file? (store/delete): ";
        string choice;
        cin >> choice;
        if (choice == "store") {
            storeSpamNumber(phoneNumber);
            cout << "The spam number has been stored in the text file." << endl;
        } else if (choice == "delete") {
            deleteSpamNumber(phoneNumber);
            cout << "The spam number has been deleted from the text file." << endl;
        } else if (choice == "read") {
            readSpamNumbers(phoneNumber);
            cout << "The spam numbers will be read and displayed from the text file." << endl;
        } else {
            cout << "Invalid choice." << endl;
        }
    } else {
        cout << "The phone number is not a spam number." << endl;
    }

    return 0;
}
