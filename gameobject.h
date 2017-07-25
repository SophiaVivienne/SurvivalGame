#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "vector2.h"

class GameObject
{
    char _icon;
    Vector2 _position;
public:
    GameObject();
    GameObject(char icon, Vector2 position);

    char getIcon();
    Vector2 getPosition();

    void setIcon(char icon);
    void setPosition(Vector2 position);
    bool operator ==(const GameObject& gameObject);
};

#endif // GAMEOBJECT_H
