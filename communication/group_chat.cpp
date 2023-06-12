#include "group_chat.h"
#include <iostream>

Group_Chat::Group_Chat() {}

Group_Chat::Group_Chat(QString sender_name, QString grpName) {

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
    sender = sender_name;
    grp_name = grpName;

    // create a query object to the database
    query = new QSqlQuery(db);

}

Group_Chat::Group_Chat(QString sender_name) {

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
    sender = sender_name;

    // create a query object to the database
    query = new QSqlQuery(db);
}

// Description: Retrieves the message from the database
QString Group_Chat::get_message() {
    QString sqlcmd = "";
    sqlcmd  += "select sender, time, message from group_chat where receiver_group = \"";
    sqlcmd += grp_name;
    sqlcmd += "\";";

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

// Description: Retrieves the description of a group by its name
QString Group_Chat::get_describe(QString name) {
    QString sqlcmd = "";
    sqlcmd  += "select group_Describe from group_table where group_name = \"";
    sqlcmd += name;
    sqlcmd += "\";";

    if(query->exec(sqlcmd) == false) {
        QSqlError err = query->lastError();
        std::cout << "error message" << std::endl;
        std::cout << err.text().toStdString() << std::endl;
    }

    QString result = "";

    while (query->next()) {
        QString des  = query->value(0).toString();

        if(des != " "){
            result += des;
        }
    }
    return result;
}

// Description: Searches for a group in the database by its name
bool Group_Chat::search_grp(QString grpname){
    QString sqlcmd = "select * from group_table where group_name = \"";
            sqlcmd += grpname;
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

// Description: Sends a message to a group chat
void Group_Chat::send_message(QString mes){
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    std::string ti = (std::string) buf;
    QString t = QString::fromStdString(ti);
    QString sqlcmd = "";
    sqlcmd += "insert into group_chat ";
    sqlcmd += "(sender, receiver_group, time, message) ";
    sqlcmd += "values (\"";
    sqlcmd += sender;
    sqlcmd += "\", \"";
    sqlcmd += grp_name;
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

// Description: Creates a new group with the provided name and description
void Group_Chat::creat_grp(QString grpName, QString grpDesc){
    QString sqlcmd = "";
    sqlcmd  = "insert into group_table (group_name, group_Describe)";
    sqlcmd += " values ( \"";
    sqlcmd += grpName;
    sqlcmd += "\", \"";
    sqlcmd += grpDesc;
    sqlcmd += "\");";

    // execute the provided sql call
    if(query->exec(sqlcmd) == false) {
        QSqlError err = query->lastError();
        qDebug() << err.text();
    }
}
