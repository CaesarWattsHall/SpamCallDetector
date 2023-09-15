/*
By: Caesar R. Watts-Hall
Date: September 15, 2023
*/

// Include the necessary libraries for Qt and SQLite
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <fstream>
#include <string>
#include <map>
#include <ctime>
#include <sqlite3.h>
using namespace std;

// Define a map to store the spam criteria
map<string, bool> spamCriteria;

// Function to load the spam criteria from a file
void loadSpamCriteria() {
    // Open the file
    ifstream file("spamCriteria.txt");
    string line;
    // Read each line from the file
    while (getline(file, line)) {
        // Ignore comment lines
        if (line[0] == '#') continue;
        // Extract the criterion and its value
        string criterion = line.substr(0, line.find("="));
        bool value = line.substr(line.find("=") + 1) == "true" ? true : false;
        // Store the criterion in the map
        spamCriteria[criterion] = value;
    }
    // Close the file
    file.close();
}

// Function to check if a phone number is spam based on the loaded criteria
bool isSpamNumber(string phoneNumber) {
    // If the number is in the whitelist, it's not spam
    if (spamCriteria["startsWith9"] && phoneNumber[0] == '9') {
        return true;
    }
    // Add more criteria here...
    return false;
}

// Function to log each call to a SQLite database
void logCall(string phoneNumber, bool isSpam) {
    // Open the database
    sqlite3* DB;
    sqlite3_open("callLogs.db", &DB);

    // Construct the SQL query to insert a new row into the table
    string sql = "INSERT INTO CALL_LOGS (PHONE_NUMBER, TIME_STAMP, IS_SPAM) VALUES ('" 
                 + phoneNumber + "', datetime('now'), " + (isSpam ? "1" : "0") + ");";

    // Execute the SQL query
    sqlite3_exec(DB, sql.c_str(), NULL, 0, NULL);

    // Close the database
    sqlite3_close(DB);
}

// The main function where the application starts
int main(int argc, char **argv) {
    // Create a Qt application object
    QApplication app(argc, argv);

    // Load the spam criteria from a file
    loadSpamCriteria();

    // Create a window widget and a layout for arranging child widgets
    QWidget window;
    QVBoxLayout layout(&window);

    // Create a label widget for displaying text and add it to the layout
    QLabel label("Enter phone number:");
    layout.addWidget(&label);

    // Create a line edit widget for entering text and add it to the layout
    QLineEdit lineEdit;
    layout.addWidget(&lineEdit);

    // Create a push button widget and add it to the layout
    QPushButton button("Check");
    layout.addWidget(&button);

    // Create another label widget for displaying the result and add it to the layout
    QLabel result;
    layout.addWidget(&result);

   // Connect the button's clicked signal to a lambda function that checks if the entered number is spam and displays the result
   QObject::connect(&button, &QPushButton::clicked, & {
        QString phoneNumber = lineEdit.text();
        bool isSpam = isSpamNumber(phoneNumber.toStdString());
        if (isSpam) {
            result.setText("The phone number is a spam number.");
        } else {
            result.setText("The phone number is not a spam number.");
        }
        logCall(phoneNumber.toStdString(), isSpam);
   });

   // Show the window and start the application's event loop
   window.show();

   return app.exec();
}
