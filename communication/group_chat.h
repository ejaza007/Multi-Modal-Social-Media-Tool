#ifndef GROUP_CHAT_H
#define GROUP_CHAT_H

#include <iostream>
#include "QString"
#include "QSqlDatabase"
#include "QSqlQuery"
#include "QSqlError"
#include "QVariant"
#include "QSqlRecord"
#include <stdio.h>
#include <time.h>

class Group_Chat {
public:
    Group_Chat();
    // Constructor with sender_name parameter
    Group_Chat(QString sender_name);

    // Constructor with sender_name and number parameters
    Group_Chat(QString sender_name, QString number);

    // Method: get_message
    // Description: Retrieves the message from the database
    QString get_message();

    // Method: search_grp
    // Description: Searches for a group in the database by its name
    bool search_grp(QString grpname);

    // Method: send_message
    // Description: Sends a message to a group chat
    void send_message(QString mes);

    // Method: creat_grp
    // Description: Creates a new group with the provided name and description
    void creat_grp(QString grpName, QString grpDesc);

    // Method: get_describe
    // Description: Retrieves the description of a group by its name
    QString get_describe(QString name);

private:
    QString sender; // The sender of a message
    QString grp_name; // The recipient group name
    QSqlDatabase db; // Database connection object
    QSqlQuery *query; // Query object for executing SQL commands

};

#endif // GROUP_CHAT_H
