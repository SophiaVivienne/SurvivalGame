#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "iostream"
#include "vector"
#include "player.h"

using namespace std;

class Gameplay
{
    string _path;
    bool gameOver;
    char _gameObjects[7] = {'a','c','i','k','s','x','j'};

    void createList();

    bool newLine(char c);
    bool gameObject(char c);
    void createMatrix(vector<GameObject*> list);
    void drawMatrix(vector<vector<char>> map, int x, int y);
    bool player(char c);
    void drawMap(vector<GameObject> list);
    void writePlayerDatas(int i);
    void updateMap();
    char getch();
    void clear();
    void exitGame(int playerIndex);

protected:
    vector<GameObject*> _gameObjectList;

public:
    Gameplay();
};

#endif // GAMEPLAY_H
