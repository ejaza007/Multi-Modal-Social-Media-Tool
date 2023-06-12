#include <iostream>
#include "fish.h"

Fish::Fish() {

}

/**
 * @brief Fish::Fish fish information that is in database, fish constructor
 * @param fId
 * @param fName
 * @param fImage
 * @param fBreed
 * @param fType
 * @param fColor
 * @param fSize
 * @param fWeight
 * @param fAge
 * @param fOwner
 */
Fish::Fish(int fId, std::string fName, std::string fImage, std::string fBreed, std::string fType, std::string fColor, float fSize, float fWeight, int fAge, std::string fOwner) {
    fishID = fId;
    fName = name;
    fImage = image;
    fBreed = breed;
    fType = type;
    fColor = coloration;
    size = fSize;
    weight = fWeight;
    age = fAge;
    fOwner = owner_username;
}

/**
 * @brief Fish::get_name obtains the name of the fish
 * @return std::string
 */
std::string Fish::get_name() {
    return name;
}

/**
 * @brief Fish::get_fishID obtains name of the fish id
 * @return int
 */
int Fish::get_fishID() {
    return fishID;
}

/**
 * @brief Fish::get_breed obtains the breed
 * @return std::string
 */
std::string Fish::get_breed() {
    return breed;
}

/**
 * @brief Fish::get_type saltwater or freshwater of the fish
 * @return std::string
 */
std::string Fish::get_type() {
    return type;
}

/**
 * @brief Fish::get_coloration color of fish
 * @return std::string
 */
std::string Fish::get_coloration() {
    return coloration;
}

/**
 * @brief Fish::get_size size of fish
 * @return float
 */
float Fish::get_size() {
    return size;
}

/**
 * @brief Fish::get_owner obtains the user that this fish belongs to
 * @return std::string
 */
std::string Fish::get_owner() {
    return owner_username;
}

/**
 * @brief Fish::get_weight weight of fish
 * @return float
 */
float Fish::get_weight() {
    return weight;
}

/**
 * @brief Fish::get_age age of fish
 * @return int
 */
int Fish::get_age() {
    return age;
}

/**
 * @brief Fish::get_image url picture of the fish
 * @return std::string
 */
std::string Fish::get_image() {
    return image;
}
