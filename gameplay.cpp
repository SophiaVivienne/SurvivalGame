#include "gameplay.h"
#include "vector2.h"
#include "fstream"

//Constructor for new gameplay
Gameplay::Gameplay()
{
    _path = "map.txt";
    createList();
    drawMap();
}

//Create GameObject list from input characters:
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

//Check the input character for new line signature:
bool Gameplay::newLine(char c){
    if(c == '\n')
        return true;
    return false;
}

//Check the input character for gameobject type:
bool Gameplay::gameObject(char c){
    for(uint i = 0; i < sizeof(_gameObjects); i++){
        if(c == _gameObjects[i])
            return true;
    }
    return false;
}

//Check the input character for player type:
bool Gameplay::player(char c){
    if(c == 'h')
        return true;
    return false;
}

//Draw the map from GameObject list:
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

//Clear the console:
void Gameplay::clear(){
    if (system("CLS"))
        system("clear");
}
