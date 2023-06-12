#include "accountmanipulator.h"
#include <iostream>

AccountManipulator::AccountManipulator() {

    // specify the location of the database
    QString path("../database_sqlite/project.sqlite");

    // create a database driver
    db = QSqlDatabase::addDatabase("QSQLITE");

    // establish a link to the database
    db.setDatabaseName(path);

    // verify the database opened, used for testing
    if (!db.open())
    {
        qDebug() << db.lastError().text();



    }
    else
    {
       std::cout  << "Database: connection ok"
                  << std::endl;
    }

    user_query = new QSqlQuery();
}


AccountManipulator::~AccountManipulator() {
    delete user_query;
    db.close();
    db.removeDatabase("../database_sqlite/project.sqlite");
}

//checks to see if an account is present
bool AccountManipulator::register_account(std::string username, std::string password) {

    if (verify_username(username)) {
        return false;
    }

    // prepares insert statement
    user_query->prepare("INSERT INTO user_table (user_name, pass, permission_level, name, address) "
                  "VALUES (:username, :password, :perms, :name, :address)");

    // adds values to insert
    user_query->bindValue(":username", QString::fromStdString(username));
    user_query->bindValue(":password", QString::fromStdString(password));
    user_query->bindValue(":perms", 1);
    user_query->bindValue(":name", "default");
    user_query->bindValue(":address", "default");

    // run command, handle errors
    if(user_query->exec() == false) {
        QSqlError err = user_query->lastError();
        qDebug() << err.text(); // TODO: deal with database error handling
        return false;
    }

    return true;
}

//obtain a user's account from the database
User AccountManipulator::get_user_account(std::string username) {

    // create variables for account values
    std::string uname;
    std::string pword;
    int permissions;
    std::string name;
    std::string address;

    // get account info form db
    user_query->prepare("select * from user_table where user_name = :uname");
    user_query->bindValue(":uname", QString::fromStdString(username));

    // need to handle errors?
    user_query->exec();

    user_query->first();

    // set the variables to the db values
    uname = user_query->value("user_name").toString().toStdString();
    pword = user_query->value("pass").toString().toStdString();
    permissions = user_query->value("permission_level").toInt();
    name = user_query->value("name").toString().toStdString();
    address = user_query->value("address").toString().toStdString();



    // create a user with the values and return it
    return User(uname, pword, permissions, name, address);
}


//TODO: look into "EXISTS" sql keyword and how to use in qt
bool AccountManipulator::verify_username(std::string username) {

    // prepare select statement and initialize value
    user_query->prepare("select * from user_table where user_name = :uname");
    user_query->bindValue(":uname", QString::fromStdString(username));

    // run command, handle errors
    if(user_query->exec() == false) {
        QSqlError err = user_query->lastError();
        qDebug() << err.text(); // TODO: deal with database error handling
    }

    if (user_query->next()) {
        return true;
    }

    return false;

}

//make sure the password matches the password of the user
bool AccountManipulator::verify_password(std::string username, std::string password) {

    // prepare select statement and initialize value
    user_query->prepare("select pass from user_table where user_name = :uname");
    user_query->bindValue(":uname", QString::fromStdString(username));

    // run command, handle errors
    if(user_query->exec() == false) {
        QSqlError err = user_query->lastError();
        qDebug() << err.text(); // TODO: deal with database error handling
    }

    user_query->first();

    return (user_query->value("pass")).toString().toStdString() == password;


}



bool AccountManipulator::change_password(std::string username, std::string new_password) {

    // prepare update statement and set values
    user_query->prepare("update user_table set pass = :new_password where user_name = :username");
    user_query->bindValue(":new_password", QString::fromStdString(new_password));
    user_query->bindValue(":username", QString::fromStdString(username));

    // run command, handle errors
    if(user_query->exec() == false) {
        QSqlError err = user_query->lastError();
        qDebug() << err.text(); // TODO: deal with database error handling
        return false;
    }

    return true;

}

bool AccountManipulator::change_permissions(std::string username, int new_perms) {

    // prepare update statement and set values
    user_query->prepare("update user_table set permission_level = :new_perms where user_name = :username");
    user_query->bindValue(":new_perms", new_perms);
    user_query->bindValue(":username", QString::fromStdString(username));

    // run command, handle errors
    if(user_query->exec() == false) {
        QSqlError err = user_query->lastError();
        qDebug() << err.text(); // TODO: deal with database error handling
        return false;
    }

    return true;


}

bool AccountManipulator::change_name(std::string username, std::string new_name) {

    // prepare update statement and set values
    user_query->prepare("update user_table set name = :new_name where user_name = :username");
    user_query->bindValue(":new_name", QString::fromStdString(new_name));
    user_query->bindValue(":username", QString::fromStdString(username));

    // run command, handle errors
    if(user_query->exec() == false) {
        QSqlError err = user_query->lastError();
        qDebug() << err.text(); // TODO: deal with database error handling
        return false;
    }

    return true;



}

bool AccountManipulator::change_address(std::string username, std::string new_address) {

    // prepare update statement and set values
    user_query->prepare("update user_table set address = :new_address where user_name = :username");
    user_query->bindValue(":new_address", QString::fromStdString(new_address));
    user_query->bindValue(":username", QString::fromStdString(username));

    // run command, handle errors
    if(user_query->exec() == false) {
        QSqlError err = user_query->lastError();
        qDebug() << err.text(); // TODO: deal with database error handling
        return false;
    }

    return true;


}

bool AccountManipulator::setup_user_score(std::string username) {

    // prepares insert statement
    user_query->prepare("INSERT INTO user_help_score (user_name, score) "
                  "VALUES (:username, 0)");

    user_query->bindValue(":username", QString::fromStdString(username));

    // run command, handle errors
    if(user_query->exec() == false) {
        QSqlError err = user_query->lastError();
        qDebug() << err.text(); // TODO: deal with database error handling
        return false;
    }

    return true;

}

std::vector<std::string> AccountManipulator::get_fish(std::string username) {

    std::vector<std::string> fish_vector;

    std::string str;


    user_query->prepare("select fish_image from fish where owner_name = :username");
    user_query->bindValue(":username", QString::fromStdString(username));

    // run command, handle errors
    if(user_query->exec() == false) {
        QSqlError err = user_query->lastError();
        qDebug() << err.text(); // TODO: deal with database error handling
    }

    while(user_query->next()) {

        str = user_query->value("fish_image").toString().toStdString();

        fish_vector.push_back(str);
    }

    return fish_vector;
}

bool AccountManipulator::add_fish(std::string fish_name, std::string fish_breed, std::string fish_image, std::string owner_name) {

    // prepares insert statement
    user_query->prepare("INSERT INTO fish (fish_id, fish_name, fish_image, breed, type, color, size, weight, age, owner_name) "
                  "VALUES ((select max(fish_id) from fish+1), :fish_name, :fish_image, 'breed', 'type', 'color', 1, 1, 1, :owner_name)");

    user_query->bindValue(":fish_name", QString::fromStdString(fish_name));
    user_query->bindValue(":fish_breed", QString::fromStdString(fish_breed));
    user_query->bindValue(":fish_image", QString::fromStdString(fish_image));
    user_query->bindValue(":owner_name", QString::fromStdString(owner_name));

    // run command, handle errors
    if(user_query->exec() == false) {
        QSqlError err = user_query->lastError();
        qDebug() << err.text(); // TODO: deal with database error handling
        return false;
    }

    return true;


}

std::vector<std::string> AccountManipulator::get_fish_names(std::string username) {

    std::vector<std::string> fish_vector;

    std::string str;

    user_query->prepare("select fish_name from fish where owner_name = :username");
    user_query->bindValue(":username", QString::fromStdString(username));

    // run command, handle errors
    if(user_query->exec() == false) {
        QSqlError err = user_query->lastError();
        qDebug() << err.text(); // TODO: deal with database error handling
    }

    while(user_query->next()) {

        str = user_query->value("fish_name").toString().toStdString();

        fish_vector.push_back(str);
    }

    return fish_vector;
}

