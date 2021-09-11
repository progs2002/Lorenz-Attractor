#include "utils.h"

RES getRES()
{
    using namespace std;
    cout << "Enter your desired window resolution in the format {Width}x{Height} or press enter for default 800x800" << endl;
    string inp;
    getline(cin, inp);
    if (inp.empty())
        return { 800,800 };
    else
    {
        int p = -1;
        for (int i = 0; i < inp.size(); i++)
        {
            if (inp.at(i) == 'x')
                p = i;
        }
        if (p != -1)
            return { stoi(inp.substr(0,p)),stoi(inp.substr(p + 1,inp.size())) };
        else
        {
            cout << "invalid input" << endl;
            return getRES();
        }
    }
}

Point* matmul_return2D(int a[2][3], Point& p)
{
    float px,py,pz;
    px = p.x * a[0][0] + p.y * a[0][1] + p.z * a[0][2];
    py = p.x * a[1][0] + p.y * a[1][1] + p.z * a[1][2];
    pz = 0;
    return new Point{px,py,pz};
}

Point* matmul_return3D(float a[3][3], Point& p)
{
    float px,py,pz;
    px = p.x * a[0][0] + p.y * a[0][1] + p.z * a[0][2];
    py = p.x * a[1][0] + p.y * a[1][1] + p.z * a[1][2];
    pz = p.x * a[2][0] + p.y * a[2][1] + p.z * a[2][2];
    return new Point{px,py,pz};
}

Point* getPoint()
{
    int x, y, z;
    std::cout << "enter a point in 3d" << std::endl;
    std::cin >> x;
    std::cin >> y;
    std::cin >> z;
    return new Point{(float)x,(float)y,(float)z};
}