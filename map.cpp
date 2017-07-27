#include "map.h"
#include "fstream"
#include "player.h"
#include "sstream"

Map::Map(vector<GameObject*> *List = new vector<GameObject*>, string Path = "NULL")
            :list(List), path(Path)
{
    createList();
}

void Map::drawMap(){
    createMatrix();
    drawMatrix();
}

//Create GameObject list from input characters:
void Map::createList(){
    char c;
    int x = 0,y = 0;
    fstream inputStream(path,fstream::in);

    while(inputStream>>noskipws>>c){
        if(c == '\n'){
            x++;
            y = 0;
        }else{
            if(gameObject(c)){
                Vector2 position(x,y);
                list->push_back(new GameObject(c,position));
            }else if(c == 'h'){
                Vector2 position(x,y);
                list->push_back(new Player(c,position,2,false,false));
            }
            y++;
        }
    }

    inputStream.close();
}

//Create Matrix from GameObject list:
void Map::createMatrix(){
    int x = list->back()->getPosition().X;
    int y = list->back()->getPosition().Y;
    int n = 0;
    exit = true;
    map.clear();

    for (int i = 0; i <= x; i++){
        vector<char> row;
        for(int j = 0; j <= y; j++){
            if((list->at(n)->getPosition().X == i) && (list->at(n)->getPosition().Y == j)){
                if(list->at(n)->getIcon() == 'j')
                    exit = false;
                if(list->at(n)->getIcon() == 'h')
                    player = n;
                row.push_back(list->at(n)->getIcon());
                n++;
            }
            else if (list->at(n)->getIcon() == 'h'){
                row.push_back(' ');
                player = n;
                n++;
            }else{
                row.push_back(' ');
            }
        }
        map.push_back(row);
    }

    map.at(list->at(player)->getPosition().X).at(list->at(player)->getPosition().Y) = 'h';
}

//Draw map from created Matrix:
void Map::drawMatrix(){
    int x = list->back()->getPosition().X;
    int y = list->back()->getPosition().Y;
    Player *_player = (Player*)list->at(player);

    for (int m = 0; m <= x; m++){
        for(int n = 0; n <= y; n++){
            cout<<map.at(m).at(n);
        }
        switch(m){
            case 0:
                cout << " HP: " << _player->getHP();
                break;
            case 1:
                cout << " Sword: " << _player->hasSword();
                break;
            case 2:
                cout << " Treasure: " << _player->hasTreasure();
                break;
            default:
                break;
        }

        cout<<endl;
    }
}

//Check the input character for gameobject type:
bool Map::gameObject(char c){
    for(uint i = 0; i < sizeof(_gameObjects); i++){
        if(c == _gameObjects[i])
            return true;
    }
    return false;
}
