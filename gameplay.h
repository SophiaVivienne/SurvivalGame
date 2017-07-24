#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "iostream"
#include "vector"
#include "player.h"

using namespace std;

class Gameplay
{
    string _path;
    char _gameObjects[7] = {'a','c','i','k','s','x','j'};

    void createList();

    bool newLine(char c);
    bool gameObject(char c);
    bool player(char c);

    void drawMap();

protected:
    vector<GameObject> gameObjectList;

public:
    Gameplay();
};

#endif // GAMEPLAY_H
