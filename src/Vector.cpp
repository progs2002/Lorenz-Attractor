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

Vector* matmul_return2D(int a[2][3], Vector& v)
{
    return new Vector(v.x * a[0][0] + v.y * a[0][1] + v.z * a[0][2], v.x * a[1][0] + v.y * a[1][1] + v.z * a[1][2]);
}

Vector* matmul_return3D(int a[3][3], Vector& v)
{
    return new Vector(v.x * a[0][0] + v.y * a[0][1] + v.z * a[0][2], v.x * a[1][0] + v.y * a[1][1] + v.z * a[1][2], v.x * a[2][0] + v.y * a[2][1] + v.z * a[2][2]);
}