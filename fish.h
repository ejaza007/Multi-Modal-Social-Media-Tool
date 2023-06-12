#ifndef FISH_H
#define FISH_H
#include <iostream>

class Fish
{
public:
    Fish();
    Fish(int fId, std::string fNname, std::string fImage, std::string fBreed, std::string fType, std::string fColor, float fSize, float fWeight, int fAge, std::string fOwner);
    std::string get_name();
    std::string get_image();
    int get_fishID();
    std::string get_breed();
    std::string get_type();
    std::string get_coloration();
    float get_size();
    std::string get_owner();
    float get_weight();
    int get_age();

private:
    int fishID; //id of someone's fish
    std::string name; //name of fish
    std::string image; //image location
    std::string breed; //breed of the fish
    std::string type; //fish lives in seawater vs. saltwater
    std::string coloration; //color of fish
    float size; //size of fish
    float weight; //weight of fish
    int age; //age of the user's fish
    std::string owner_username; //owner of fish
};

#endif // FISH_H
