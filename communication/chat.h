#ifndef CHAT_H
#define CHAT_H

#include <iostream>

#include "QString"
#include "QSqlDatabase"
#include "QSqlQuery"
#include "QSqlError"
#include "QVariant"
#include "QSqlRecord"
#include <stdio.h>
#include <time.h>

// Define the Chat class, which represents a chat between two users.
class Chat {
public:
    // Declare three overloaded constructors for the Chat class.
    Chat();
    Chat(QString sender_name);
    Chat(QString sender_name, QString reciever_name);

    // Declare a function to search for a receiver using their username.
    bool search_reciever(QString username);

    // Declare a function to display the current message.
    QString display_message();

    // Declare a function to send a text message.
    void send_message(QString mes);

    // Declare a function to send an image using a URL.
    void send_image(std::string url);

    // Declare a function to receive a single contact.
    std::string* rec_contact();

    // Declare a function to receive a list of contacts.
    std::string* rec_contacts();

    void setSender(std::string a);

    void setReceiver(std::string a);

private:
    // Declare private member variables for the sender, receiver, database connection, and SQL query.
    QString       sender; // The user who sent the message.
    QString       receiver; // The user who received the message.
    QSqlDatabase  db; // The database connection.
    QSqlQuery     *query; // The SQL query object.
};

#endif // CHAT_H
