#include "gameplay.h"
#include "vector2.h"
#include "fstream"
#include "controller.h"
#include "unistd.h"
#include "termios.h"
#include "sstream"
#include "dirent.h"


//Constructor for new gameplay
Gameplay::Gameplay()
{
    start();
}

void Gameplay::start(){
    choseMap();
    createMap();
    updateMap();
}


bool Gameplay::hasSuffix(const string& s, const string& suffix)
{
    return (s.size() >= suffix.size()) && equal(suffix.rbegin(), suffix.rend(), s.rbegin());
}

void Gameplay::choseMap(){
    string path = "Maps";

    DIR *dir = opendir(path.c_str());
    if(!dir)
    {
        return;
    }    Map *map = new Map(&_gameObjectList, _path);

    dirent *entry;
    while((entry = readdir(dir))!=NULL)
    {
        if(hasSuffix(entry->d_name, ".txt"))
        {
            maps.push_back(entry->d_name);
        }
    }

    closedir(dir);

    cout << "Which map do you want? (Chose a number!)\n";
    for(int i = 0; i < maps.size(); i++)
        cout << i << ". " << maps.at(i) << endl;

    bool isValid = false;
    uint n;

    while(!isValid){
       cin >> n;
       if(n <= maps.size())
           isValid = true;
    }

    _path = maps.at(n);
    clear();
}

void Gameplay::createMap(){
    map = new Map(&_gameObjectList, _path);
    map->drawMap();
}

//Update map:
void Gameplay::updateMap(){
    Controller controller(&_gameObjectList);
    char inputChar;
    //map->exit = false;

    while(!map->exit){
        inputChar = getch();
        controller.input(inputChar);
         clear();
         map->drawMap();
    }
    exitGame(map->player);

}

//TODO:
/*void Gameplay::restart(){
    bool validChar = false;
    char inputChar;
    cout << "\nDo you want to play again? (y/n)\n";
    do{
    inputChar = getch();

    if(inputChar == 'y' || inputChar == 'n')
        validChar = true;
    else
        cout << "Invalid character input please type again!\n";

    }while(!validChar);

    clear();

    if(inputChar == 'y')
        start();
}*/

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

    _gameObjectList.clear();
    maps.clear();

    //restart();
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
    if (system("clear"))
        system("CLS");
}
