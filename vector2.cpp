#include "vector2.h"

//Constructor with default values:
Vector2::Vector2(int x = 0, int y = 0)
                    :X(x),Y(y)
{
}

//Operator overloading for equality:
bool Vector2::operator ==(const Vector2& vector) {
   if(X == vector.X && Y == vector.Y)
      return true;
   return false;
}
