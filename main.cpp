#include <iostream>

#include "QString"
#include "QSqlDatabase"
#include "QSqlQuery"
#include "QSqlError"
#include "QVariant"
#include <string>

#include "fish.h"
#include "user.h"
#include "accountmanipulator.h"

using namespace std;

int main() {

//    QString path("../database_sqlite/project.sqlite");

//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

//    db.setDatabaseName(path);

//    if (!db.open())
//    {
//       std::cout << "Error: connection with database fail"
//                 << std::endl;
//       exit(1);
//    }
//    else
//    {
//       std::cout  << "Database: connection ok"
//                  << std::endl;
//    }

//    User* test_user1 = new User("loganmca", "password", 1, "logan", "1234");
//    Fish* test_fish = new Fish(1, "nemo", "clownfish", "saltwater", "orange", 17.0, 0.5, 4, "loganmca");




//    QString username = QString::fromStdString(test_user1->get_username());
//    QString password = QString::fromStdString(test_user1->get_password());
//    QString name = QString::fromStdString(test_user1->get_name());
//    QString address = QString::fromStdString(test_user1->get_address());


//    QString breed = QString::fromStdString(test_fish->get_breed());
//    QString type = QString::fromStdString(test_fish->get_type());
//    QString fname = QString::fromStdString(test_fish->get_name());
//    QString coloration = QString::fromStdString(test_fish->get_coloration());
//    QString owner_username = QString::fromStdString(test_fish->get_owner());




//    QSqlQuery query(db);

//    query.prepare("INSERT INTO user (user_name, password, permission_level, name, address) "
//                  "VALUES (:username, :password, :perms, :name, :address)");

//    query.bindValue(":username", username);
//    query.bindValue(":password", password);
//    query.bindValue(":perms", test_user1->get_permissions());
//    query.bindValue(":name", name);
//    query.bindValue(":address", address);

//    query.exec();

//    QSqlQuery query2(db);



//    query2.prepare("INSERT INTO fish (fish_id, fish_name, breed, type, color, size, weight, age, owner_name) "
//                  "VALUES (:id, :fname, :breed, :type, :coloration, :size, :weight, :age, :owner_username)");



//    query2.bindValue(":id", test_fish -> get_fishID());
//    query2.bindValue(":fname", fname);
//    query2.bindValue(":breed", breed);
//    query2.bindValue(":type", type);
//    query2.bindValue(":coloration", coloration);
//    query2.bindValue(":size", test_fish -> get_size());
//    query2.bindValue(":weight", test_fish -> get_weight());
//    query2.bindValue(":age", test_fish -> get_age());
//    query2.bindValue(":owner_username", owner_username);

//    query2.exec();


//    AccountManipulator test_login;

//    cout << test_login.register_account("Logan", "1234") << "\n";

//    cout << test_login.verify_username("Logan") << "\n";

//    cout << test_login.verify_password("Logan", "1234") << "\n";

//    User test_user = test_login.get_user_account("Logan");

//    cout << test_user.get_username() << " " << test_user.get_password() << " "
//         << test_user.get_permissions() << " " << test_user.get_name() << " "
//         << test_user.get_address() << "\n";

//    test_login.change_password("Logan", "newpassword");

//    cout << test_login.verify_password("Logan", "newpassword") << "\n";

//    cout << test_login.change_permissions("Logan", 2) << "\n";

//    cout << test_login.change_name("Logan", "Logan") << "\n";

//    cout << test_login.change_address("Logan", "South College") << "\n";


//    return 0;

    AccountManipulator* acc = new AccountManipulator(); //a new account being created
}
