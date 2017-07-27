#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "iostream"
#include "vector"
#include "player.h"
#include "map.h"

using namespace std;

class Gameplay
{
//----------------------PLAY.H:
    string _path;

    void choseMap();
    void createMap();
    void updateMap();

    bool hasSuffix(const string& s, const string& suffix);
//----------------------MARAD:
    bool gameOver;

    void start();
    void restart();
    void exitGame(int playerIndex);


    char getch();
    void clear();

protected:
    vector<string> maps;
    Map *map;
    vector<GameObject*> _gameObjectList;

public:
    Gameplay();
    void createGame(); //new
};

#endif // GAMEPLAY_H
