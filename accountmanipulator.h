#ifndef ACCOUNTMANIPULATOR_H
#define ACCOUNTMANIPULATOR_H

#include <iostream>
#include "QString"
#include "QSqlDatabase"
#include "QSqlQuery"
#include "QSqlError"
#include "QVariant"
#include <string>

#include "user.h"

class AccountManipulator
{
public:
    /**
     * @brief AccountManipulator constructor for account manipulator, opens
     * connection to database
     */
    AccountManipulator();

    ~AccountManipulator();

    std::vector<std::string> get_fish(std::string fish_id);

    /**
     * @brief register_account adds a new user account to the database
     * @param username account username
     * @param password account password
     * @return true if successfully added, false if not
     */
    bool register_account(std::string username, std::string password);

    /**
     * @brief get_user_account gets user account info and stores it as User object
     * @param username username of account
     * @return User holding values taken from db
     */
    User get_user_account(std::string username);

    /**
     * @brief verify_username verifies that an account with the username exists in the db
     * @param username that is checked
     * @return true if username exists, false if not
     */
    bool verify_username(std::string username);

    /**
     * @brief verify_password verifies that the given password is correct for the
     * account with the given username
     * @param username of account
     * @param password of account
     * @return true if password is correct, false if not
     */
    bool verify_password(std::string username, std::string password);

    /**
     * @brief change_password changes the password of a user account in the db
     * @param username of account
     * @param new_password new password for account
     * @return true if changed successfully, false if not
     */
    bool change_password(std::string username, std::string new_password);

    /**
     * @brief change_permissions changes the permission level of a user account in the db
     * @param username of account
     * @param new_perms new permission level for account
     * @return true if changed successfully, false if not
     */
    bool change_permissions(std::string username, int new_perms);

    /**
     * @brief change_name changes the name associated with a user account
     * @param username of account
     * @param new_name new name for account
     * @return true if changed successfully, false if not
     */
    bool change_name(std::string username, std::string new_name);

    /**
     * @brief change_address changes the address associated with a user account
     * @param username of account
     * @param new_address new address for account
     * @return true if changed successfully, false if not
     */
    bool change_address(std::string username, std::string new_address);

    //unused
    bool setup_user_score(std::string username);

    /**
     * @brief add_fish adds fish to database
     * @param fish_name name of fish
     * @param fish_breed breed of fish
     * @param fish_image fish image file location
     * @param owner_name name of owner of fish, tied to username
     * @return true if successful, false if not
     */
    bool add_fish(std::string fish_name, std::string fish_breed, std::string fish_image, std::string owner_name);


    /**
     * @brief get_fish_names gets names of fish of a given user in db
     * @param username username of user
     * @return vector of fish names
     */
    std::vector<std::string> get_fish_names(std::string username);


private:
    QSqlDatabase db;
    QSqlQuery *user_query;

};

#endif // ACCOUNTMANIPULATOR_H
