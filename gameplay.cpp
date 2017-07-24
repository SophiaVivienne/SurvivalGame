#include "gameplay.h"
#include "vector2.h"
#include "fstream"

Gameplay::Gameplay()
{
    _path = "map.txt";
    createList();
    drawMap();
}

void Gameplay::createList(){
    char c;
    int x = 0,y = 0;
    fstream inputStream(_path,fstream::in);

    while(inputStream>>noskipws>>c){
        if(newLine(c)){
            x++;
            y = 0;
        }else{
            if(gameObject(c)){
                Vector2 position(x,y);
                gameObjectList.push_back(GameObject(c,position));
            }else if(player(c)){
                Vector2 position(x,y);
                gameObjectList.push_back(Player(c,position,2,false,false));
            }
            y++;
        }
    }

    inputStream.close();
}

bool Gameplay::newLine(char c){
    if(c == '\n')
        return true;
    return false;
}

bool Gameplay::gameObject(char c){
    for(uint i = 0; i < sizeof(_gameObjects); i++){
        if(c == _gameObjects[i])
            return true;
    }
    return false;
}

bool Gameplay::player(char c){
    if(c == 'h')
        return true;
    return false;
}

void Gameplay::drawMap(){
    int i =0, j = 0, k = 0;
    int x = gameObjectList.back().getPosition().X;
    int y = gameObjectList.back().getPosition().Y;

    while(i <= x){
        j = 0;
        while(j <= y){
            if((gameObjectList.at(k).getPosition().X == i) && (gameObjectList.at(k).getPosition().Y == j)){
                cout<<gameObjectList.at(k).getIcon();
                k++;
            }
            else{
                cout<<' ';
            }
            j++;
        }
        cout<<endl;
        i++;
    }
}
