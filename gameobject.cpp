#include "gameobject.h"

GameObject::GameObject(char icon = '@', Vector2 position = Vector2 (0,0))
                        :_icon(icon),_position(position)
{
}

char GameObject::getIcon(){
    return _icon;
}

Vector2 GameObject::getPosition(){
    return _position;
}

void GameObject::setIcon(char icon){
    _icon = icon;
}

void GameObject::setPosition(Vector2 position){
    _position = position;
}
