#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "iostream"
#include "vector"
#include "vector2.h"
#include "player.h"

using namespace std;

class Controller
{
    vector<GameObject*> *_gameobjectList;
    void interaction(int i, Vector2 nextPosition);
    int getGameObjectByIcon(char c);
    int getGameObjectByPosition(Vector2 nextPosition);
    void deleteGameObject(Vector2 nextPosition);

    void moveToEmpty(Player *player,Vector2 nextPosition);
    void moveToSword(Player *player,Vector2 nextPosition);
    void moveToMonster(Player *player,Vector2 nextPosition);
    void moveToPotion(Player *player,Vector2 nextPosition);
    void moveToChest(Player *player,Vector2 nextPosition);
    void moveToTrap(Player *player,Vector2 nextPosition);
    void exit(Player *player, Vector2 nextPosition);
public:
    Controller();
    Controller(vector<GameObject*> *gameobjectList);
    void input(char inputChar);
};

#endif // CONTROLLER_H
