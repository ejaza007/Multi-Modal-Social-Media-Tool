#include "user.h"

User::User()
{

}

/**
 * @brief User::User user inforamtion from the database, constructor
 * @param uname
 * @param pword
 * @param perms
 * @param nme
 * @param addr
 */
User::User(std::string uname, std::string pword, int perms, std::string nme, std::string addr) {

    username = uname;
    password = pword;
    permissions = perms;
    name = nme;
    address = addr;

}

/**
 * @brief User::get_username obtains username
 * @return std::string
 */
std::string User::get_username() {
    return username;
}

/**
 * @brief User::get_password obtains password
 * @return std::string
 */
std::string User::get_password() {
    return password;
}

/**
 * @brief User::get_permissions permission level
 * @return int
 */
int User::get_permissions() {
    return permissions;
}

/**
 * @brief User::get_name obtains the name of the user
 * @return std::string
 */
std::string User::get_name() {
    return name;
}

/**
 * @brief User::get_address town of user if they add one
 * @return std::string
 */
std::string User::get_address() {
    return address;
}
