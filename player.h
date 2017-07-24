#ifndef PLAYER_H
#define PLAYER_H
#include "gameobject.h"

class Player : public GameObject
{
    int _hp;
    bool _hasSword;
    bool _hasChest;
public:
    const int MaxHp = 2;

    Player();
    Player(char Icon, Vector2 Position, int _hp, bool _hasSword, bool _hasChest);

    int getHP();
    bool hasSword();
    bool hasChest();

    void setHp(int hp);
    void setHasSword(bool hasSword);
    void setHasChest(bool hasChest);
};

#endif // PLAYER_H
