#include "player.h"

Player::Player(char icon = '@', Vector2 position = Vector2 (1,1), int hp = 2,
               bool hasSword = false, bool hasChest = false)
              :GameObject(icon,position), _hp(hp), _hasSword(hasSword),
                 _hasChest(hasChest)
{
}

int Player::getHP(){
    return _hp;
}

bool Player::hasSword(){
    return _hasSword;
}

bool Player::hasChest(){
    return _hasChest;
}

void Player::setHp(int hp){
    _hp = hp;
}

void Player::setHasSword(bool hasSword){
    _hasSword = hasSword;
}

void Player::setHasChest(bool hasChest){
    _hasChest = hasChest;
}
