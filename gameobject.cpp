#include "gameobject.h"

//Constructor with default values:
GameObject::GameObject(char icon = '@', Vector2 position = Vector2 (0,0))
                        :_icon(icon),_position(position)
{
}

//Get the icon of current GameObject:
char GameObject::getIcon(){
    return _icon;
}

//Get the position of current GameObject:
Vector2 GameObject::getPosition(){
    return _position;
}

//Set the icon of current GameObject:
void GameObject::setIcon(char icon){
    _icon = icon;
}

//Set the position of current GameObject:
void GameObject::setPosition(Vector2 position){
    _position = position;
}
