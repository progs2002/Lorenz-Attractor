#pragma once
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include "Vector.h"

struct RES { int W, H; };
struct Point {float x, y, z; };
RES getRES();
Point* matmul_return2D(int a[2][3], Point& p);
Point* matmul_return3D(float a[3][3], Point& p);
Point* getPoint();