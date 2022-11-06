#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    
    int x_min = dots[0][0];
    int x_max = dots[0][0];
    int y_min = dots[0][1];
    int y_max = dots[0][1];
    for (auto d : dots) {
        if (d[0] < x_min) x_min = d[0];
        if (d[0] > x_max) x_max = d[0];
        if (d[1] < y_min) y_min = d[1];
        if (d[1] > y_max) y_max = d[1];
    }
    return (x_max - x_min) * (y_max - y_min);
}