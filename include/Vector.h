#pragma once 
class Vector
{
public:
    float x, y, z;
    Vector(float x, float y);
    Vector(float x, float y, float z);
    float dotProduct(Vector& v);
    Vector* crossProduct(Vector& v);
};
