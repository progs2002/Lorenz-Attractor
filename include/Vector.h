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
Vector* matmul_return2D(int a[2][3], Vector& v);
Vector* matmul_return3D(int a[3][3], Vector& v);