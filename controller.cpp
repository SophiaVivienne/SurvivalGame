#include "controller.h"

Controller::Controller(vector<GameObject*> *gameobjectList)
                        :_gameobjectList(gameobjectList)
{
}

//Move by input character:
void Controller::input(char inputChar){
    int i;

    i = getGameObjectByIcon('h');

    Vector2 playerPosition = _gameobjectList->at(i)->getPosition();
    Vector2 nextPosition = playerPosition;

    bool validInput = true;
    switch(inputChar){
        case 'w':
            nextPosition.X--;
            break;
        case 's':
            nextPosition.X++;
            break;
        case 'a':
            nextPosition.Y--;
            break;
        case 'd':
            nextPosition.Y++;
            break;
        default:
            validInput = false;
            break;
    }

    if(validInput){
        interaction(i,nextPosition);
    }
}

//Movement interactions:
void Controller::interaction(int i, Vector2 nextPosition){
    Player *player = (Player*)_gameobjectList->at(i);
    char c;

    try{
        c = _gameobjectList->at(getGameObjectByPosition(nextPosition))->getIcon();
    }catch(int i){
        c = ' ';
    }

    switch(c){
        case ' ':
            moveToEmpty(player,nextPosition);
            break;
        case 'a':
            moveToSword(player,nextPosition);
            break;
        case 's':
            moveToMonster(player,nextPosition);
            break;
        case 'i':
            moveToPotion(player,nextPosition);
            break;
        case 'k':
            moveToChest(player,nextPosition);
            break;
        case 'c':
            moveToTrap(player,nextPosition);
            break;
        case 'j':
            exit(player,nextPosition);
            break;
        default:

            break;
    }
}

//Get GameObjectList list iterator by icon:
int Controller::getGameObjectByIcon(char c){
    int i = 0;
    int max = _gameobjectList->size();

    while(i != max){
        if(_gameobjectList->at(i)->getIcon() == c)
            return i;
        i++;
    }
    throw 0;
}

//Get GameObject list iterator by position:
int Controller::getGameObjectByPosition(Vector2 nextPosition){
    int i = 0;
    int max = _gameobjectList->size();

    while(i != max){
        if(_gameobjectList->at(i)->getPosition() == nextPosition)
            return i;
        i++;
    }
    throw 0;
}

//Delete GameObject from next player position:
void Controller::deleteGameObject(Vector2 nextPosition){
    _gameobjectList->erase(_gameobjectList->begin()+getGameObjectByPosition(nextPosition));
}

//Move to empty space:
void Controller::moveToEmpty(Player *player, Vector2 nextPosition){
    player->setPosition(nextPosition);
}

//Pick up the sword and move there:
void Controller::moveToSword(Player *player, Vector2 nextPosition){
    deleteGameObject(nextPosition);
    player->setHasSword(true);
    player->setPosition(nextPosition);
}

//Fight with monster and move there:
void Controller::moveToMonster(Player *player, Vector2 nextPosition){
    int currentHp = player->getHP();
    if(player->hasSword()){
        deleteGameObject(nextPosition);
        player->setHp(currentHp-1);
        player->setPosition(nextPosition);
    }else{
        player->setHp(0);
    }

    if(player->getHP() == 0){
        int n = getGameObjectByIcon('j');
        Vector2 exitPosition =_gameobjectList->at(n)->getPosition();
        exit(player,exitPosition);
    }
}

//Pick up potion if player doesn't have full HP and move there:
void Controller::moveToPotion(Player *player, Vector2 nextPosition){
    int currentHp = player->getHP();
    if(currentHp != player->MaxHp){
        player->setHp(currentHp+1);
        deleteGameObject(nextPosition);
    }
    player->setPosition(nextPosition);
}

//Pick up the Treasure and move there:
void Controller::moveToChest(Player *player, Vector2 nextPosition){
    player->setHasTreasure(true);
    deleteGameObject(nextPosition);
    player->setPosition(nextPosition);
}

//Jump throw the trap:
void Controller::moveToTrap(Player *player, Vector2 nextPosition){
    _gameobjectList->at(getGameObjectByPosition(nextPosition))->setIcon('x');
    player->setPosition(nextPosition);
}

void Controller::exit(Player *player, Vector2 nextPosition){
    deleteGameObject(nextPosition);
    player->setPosition(nextPosition);
}

