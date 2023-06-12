#include "chat.h"
#include  <iostream>

Chat::Chat() { }

Chat::Chat(QString sender_name) {
    db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("../database_sqlite/project.sqlite");

    if (!db.open()) {
        std::cerr << "Error: connection with database fail"
                  << std::endl;
        exit(1);
    } else {
        std::cout  << "Database: connection ok"
                   << std::endl;
    }

    // create a query object to the database
    query = new QSqlQuery(db);

    sender = sender_name;
    receiver = "";
}

Chat::Chat(QString sender_name, QString reciever_name) {
    db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("../database_sqlite/project.sqlite");

    if (!db.open()) {
        std::cerr << "Error: connection with database fail"
                  << std::endl;
        exit(1);
    } else {
        std::cout  << "Database: connection ok"
                   << std::endl;
    }

    // create a query object to the database
    query = new QSqlQuery(db);
    sender = sender_name;
    receiver = reciever_name;
}

// Declare a function to search for a receiver using their username.
bool Chat::search_reciever(QString username){
    QString sqlcmd = "select * from user_table where user_name = \"";
            sqlcmd += username;
            sqlcmd += "\";";

    // run command, handle errors
    if(query->exec(sqlcmd) == false) {
        QSqlError err = query->lastError();
        qDebug() << err.text(); // TODO: deal with database error handling
    }

    if (query->next()) {
        return true;
    }

    return false;
}

// Declare a function to display the current message.
QString Chat::display_message() {
    QString sqlcmd = "";
    sqlcmd  += "select sender, time, message from chat where (sender = \"";
    sqlcmd += sender;
    sqlcmd += "\" and receiver = \"";
    sqlcmd += receiver;
    sqlcmd += "\") or (sender = \"";
    sqlcmd += receiver;
    sqlcmd += "\" and receiver = \"";
    sqlcmd += sender;
    sqlcmd += "\");";

    if(query->exec(sqlcmd) == false) {
        QSqlError err = query->lastError();
        std::cout << "error message" << std::endl;
        std::cout << err.text().toStdString() << std::endl;
    }

    QString result = "";

    while (query->next()) {
        QString sender  = query->value(0).toString();
        QString time    = query->value(1).toString();
        QString message = query->value(2).toString();

        if(message != " "){
            result += time;
            result += " ";
            result += sender;
            result += " : ";
            result += message;
            result += "\n";
        }
    }
    return result;
}

// Declare a function to send a text message.
void Chat::send_message(QString mes){
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    std::string ti = (std::string) buf;
    QString t = QString::fromStdString(ti);
    QString sqlcmd = "";
    sqlcmd += "insert into chat ";
    sqlcmd += "(sender, receiver, time, message) ";
    sqlcmd += "values (\"";
    sqlcmd += sender;
    sqlcmd += "\", \"";
    sqlcmd += receiver;
    sqlcmd += "\", \"";
    sqlcmd += t;
    sqlcmd += "\", \"";
    sqlcmd += mes;
    sqlcmd += "\");";

    // execute the provided sql call
    if(query->exec(sqlcmd) == false) {
        QSqlError err = query->lastError();
        qDebug() << err.text();
    }
}

// Declare a function to send an image using a URL.
void Chat::send_image(std::string url){
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    std::string ti = (std::string) buf;
    QString t = QString::fromStdString(ti);
    QString me = QString::fromStdString(url);
    QString sqlcmd = "";
    sqlcmd  = "insert into chat (sender, receiver, time, message) ";
    sqlcmd += "values ( ";
    sqlcmd += sender;
    sqlcmd += ", ";
    sqlcmd += receiver;
    sqlcmd += ", ";
    sqlcmd += t;
    sqlcmd += ", ";
    sqlcmd += " ";
    sqlcmd += ", ";
    sqlcmd += me;
    sqlcmd += ");";

    // execute the provided sql call
    if(query->exec(sqlcmd) == false) {
        QSqlError err = query->lastError();
        qDebug() << err.text();
    }
}

// Declare a function to receive a single contact.
std::string* Chat::rec_contact(){
    std::string* str = new std::string[4];
    QString sqlcmd = "";
    sqlcmd  += "select distinct receiver from chat where sender = \"";
    sqlcmd += sender;
    sqlcmd += "\";";

    if(query->exec(sqlcmd) == false) {
        QSqlError err = query->lastError();
        qDebug() << err.text();
    }

    int count = 0;
    while (query->next()) {
        std::string receiver  = query->value(0).toString().toStdString();
        if (count < 4) {
            str[count] = receiver;
        } else {
            break;
        }
        count++;
    }
    return str;
}

// Declare a function to receive a list of contacts.
std::string* Chat::rec_contacts(){
    std::string* str = new std::string[4];
    QString sqlcmd = "";
    sqlcmd  += "select distinct receiver_group from group_chat where sender = \"";
    sqlcmd += sender;
    sqlcmd += "\";";

    if(query->exec(sqlcmd) == false) {
        QSqlError err = query->lastError();
        qDebug() << err.text();
    }

    int count = 0;
    while (query->next()) {
        std::string receiver  = query->value(0).toString().toStdString();
        if (count < 4) {
            str[count] = receiver;
        } else {
            break;
        }
        count++;
    }
    return str;
}

void Chat::setSender(std::string a){
    QString aa = QString::fromStdString(a);
    sender = aa;
}

void Chat::setReceiver(std::string a){
    QString aa = QString::fromStdString(a);
    receiver = aa;
}
