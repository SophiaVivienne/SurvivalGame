#include "player.h"

//Constructor with default values:
Player::Player(char icon = '@', Vector2 position = Vector2 (1,1), int hp = 2,
               bool hasSword = false, bool hasTreasure = false)
              :GameObject(icon,position), _hp(hp), _hasSword(hasSword),
                 _hasTreasure(hasTreasure)
{
}

//Get the player's health point:
int Player::getHP(){
    return _hp;
}

//Return true if the player has sword:
bool Player::hasSword(){
    return _hasSword;
}

//Return true if the player has the treasure:
bool Player::hasTreasure(){
    return _hasTreasure;
}

//Set the player's health point:
void Player::setHp(int hp){
    _hp = hp;
}

//Set if the player pick the sword:
void Player::setHasSword(bool hasSword){
    _hasSword = hasSword;
}

//Set if the player pick the treasure:
void Player::setHasTreasure(bool hasTreasure){
    _hasTreasure = hasTreasure;
}
