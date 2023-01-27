#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> dots) {

    float value1 = float(dots[0][0] - dots[2][0]) / float(dots[0][1] - dots[2][1]);
    float value2 = float(dots[1][0] - dots[3][0]) / float(dots[1][1] - dots[3][1]);
    
    if (value1 == value2) return 1;
    
    value1 = float(dots[0][0] - dots[1][0]) / float(dots[0][1] - dots[1][1]);
    value2 = float(dots[2][0] - dots[3][0]) / float(dots[2][1] - dots[3][1]);
    
    if (value1 == value2) return 1;
    
    return 0;
}