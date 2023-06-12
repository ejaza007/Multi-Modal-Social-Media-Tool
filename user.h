#ifndef USER_H
#define USER_H

#include <string>

class User
{
public:
    User();
    User(std::string uname, std::string pword, int perms, std::string nme, std::string addr);

    std::string get_username();
    std::string get_password();
    int get_permissions();
    std::string get_name();
    std::string get_address();

private:

    std::string username;
    std::string password;
    int permissions; //what access do they have (0 means suspended - the lowest permission)
    std::string name; //name of user
    std::string address;


};

#endif // USER_H
