#ifndef VECTOR2_H
#define VECTOR2_H


class Vector2
{
public:
    int X;
    int Y;
    Vector2();
    Vector2(int x, int y);
    bool operator ==(const Vector2& vector);
};

#endif // VECTOR2_H
