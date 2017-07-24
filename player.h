#ifndef PLAYER_H
#define PLAYER_H
#include "gameobject.h"

class Player : public GameObject
{
    int _hp;
    bool _hasSword;
    bool _hasTreasure;
public:
    const int MaxHp = 2;

    Player();
    Player(char Icon, Vector2 Position, int _hp, bool _hasSword, bool _hasTreasure);

    int getHP();
    bool hasSword();
    bool hasTreasure();

    void setHp(int hp);
    void setHasSword(bool hasSword);
    void setHasTreasure(bool hasTreasure);
};

#endif // PLAYER_H
