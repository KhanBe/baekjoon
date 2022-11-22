#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int p = 0;
    int y = 0;
    
    for (auto a : s) {
        if (a == 'p' || a == 'P') p++;
        else if (a == 'y' || a == 'Y') y++;
    }
    
    return p == y ? true : false;
}