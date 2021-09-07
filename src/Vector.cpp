#include "Vector.h"

Vector::Vector(float x, float y)
{
    this->x = x;
    this->y = y;
    this->z = 0.0f;
}

Vector::Vector(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

float Vector::dotProduct(Vector& v)
{
    return (this->x * v.x) + (this->y * v.y) + (this->z * v.z);
}

Vector* Vector::crossProduct(Vector &v)
{
    return new Vector((this->y * v.z - this->z * v.y), - (this->x * v.z - this->z * v.x), (this->x * v.y - this->y * v.x));
}

