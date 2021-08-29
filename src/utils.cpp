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