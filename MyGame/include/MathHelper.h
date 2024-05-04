#ifndef MathHelper_H_
#define MathHelper_H_

#include <cmath>

#define PI 3.14159265
#define DEG_TO_RAD PI / 180.0f

struct Vector2{
    float x, y;
    Vector2(float Nx = 0.0f, float Ny = 0.0f)
        :x(Nx), y(Ny) {};

    float MagnitudeSqrt(){
        return (x*x) + (y*y);
    }
    float Magnitude(){
        return (float)sqrt((x*x) + (y*y));
    }

    Vector2 Normalized(){
        float Mag = Magnitude();

        return Vector2(x / Mag, y / Mag);
    }

    Vector2 &operator +=(const Vector2 &rhs){
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    Vector2 &operator -=(const Vector2 &rhs){
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }
};

inline Vector2 operator +(const Vector2 &lhs, const Vector2 &rhs){
    return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
}

inline Vector2 operator -(const Vector2 &lhs, const Vector2 &rhs){
    return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
}

inline Vector2 operator *(const Vector2 &lhs, const float &rhs){
    return Vector2(lhs.x * rhs, lhs.y * rhs);
}

inline Vector2 Rotatevector(Vector2 & vec, float angle){
    float radAngle = (float)(angle*DEG_TO_RAD);
    return Vector2((float)(vec.x * cos(radAngle) - vec.y * sin(radAngle)), (float)(vec.x * sin(radAngle) + vec.y * cos(radAngle)));
}

const Vector2 VEC2_ZERO = {0.0f, 0.0f};
const Vector2 VEC2_ONE = {1.0f, 1.0f};
const Vector2 VEC2_UP = {0.0f, 1.0f};
const Vector2 VEC2_RIGHT = {1.0f, 0.0f};

#endif