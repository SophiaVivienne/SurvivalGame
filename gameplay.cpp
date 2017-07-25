#include "gameplay.h"
#include "vector2.h"
#include "fstream"
#include "controller.h"
#include "unistd.h"
#include "termios.h"

//Constructor for new gameplay
Gameplay::Gameplay()
{
    _path = "map.txt";
    createList();
    createMatrix(_gameObjectList);
    //drawMap(_gameObjectList);
    updateMap();
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
                _gameObjectList.push_back(new GameObject(c,position));
            }else if(player(c)){
                Vector2 position(x,y);
                _gameObjectList.push_back(new Player(c,position,2,false,false));
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

//Create Matrix from GameObject list:
void Gameplay::createMatrix(vector<GameObject*> list){
    vector<vector<char>> map;
    int n = 0;
    int player;
    bool exit = true;
    int x = list.back()->getPosition().X;
    int y = list.back()->getPosition().Y;

    for (int i = 0; i <= x; i++){
        vector<char> row;
        for(int j = 0; j <= y; j++){
            if((list.at(n)->getPosition().X == i) && (list.at(n)->getPosition().Y == j)){
                if(list.at(n)->getIcon() == 'j')
                    exit = false;
                row.push_back(list.at(n)->getIcon());
                n++;
            }
            else if (list.at(n)->getIcon() == 'h'){
                row.push_back(' ');
                player = n;
                n++;
            }else{
                row.push_back(' ');
            }
        }
        map.push_back(row);
    }

    map.at(list.at(player)->getPosition().X).at(list.at(player)->getPosition().Y) = 'h';

    drawMatrix(map,x,y);

    if(exit)
        exitGame(player);
}

//Draw map from created Matrix:
void Gameplay::drawMatrix(vector<vector<char>> map, int x, int y){
    for (int m = 0; m <= x; m++){
        for(int n = 0; n <= y; n++){
            cout<<map.at(m).at(n);
        }
        cout<<endl;
    }
}

//Update map:
void Gameplay::updateMap(){
    Controller controller(&_gameObjectList);
    char inputChar;
    gameOver = false;

    while(!gameOver){
        inputChar = getch();
        clear();
        controller.input(inputChar);
        createMatrix(_gameObjectList);
    }
}

//Get character:
char Gameplay::getch() {
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}

//Clear the console:
void Gameplay::clear(){
    if (system("CLS"))
        system("clear");
}

//Game ending:
void Gameplay::exitGame(int playerIndex){
    clear();
    Player *player = (Player*)_gameObjectList.at(playerIndex);
    if(player->hasTreasure() && player->getHP() > 0)
        cout<< "Victory!!!\n";
    else if (player->getHP() > 0)
        cout<< "Surrender.\n";
    else
        cout<< "Defeat...\n";
    gameOver = true;
}
