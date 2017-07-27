#ifndef MAP_H
#define MAP_H
#include "gameobject.h"
#include "vector"
#include "iostream"

using namespace std;

class Map
{
    string path;
    vector<GameObject*> *list;
    vector<vector<char>> map;
    char _gameObjects[7] = {'a','c','i','k','s','x','j'};

    void createList();
    void createMatrix();
    void drawMatrix();
    void writePlayerDetails(int i);

    bool gameObject(char c);

public:
    Map();

    bool exit;
    int player;
    Map(vector<GameObject*> *List, string Path);

    void drawMap();
};

#endif // MAP_H
