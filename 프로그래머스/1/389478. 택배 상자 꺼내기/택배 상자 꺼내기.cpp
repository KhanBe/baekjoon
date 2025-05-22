#include <string>
#include <vector>
#include <iostream>

using namespace std;
int v[100][100];

int solution(int n, int w, int num) {
    int answer = 0;
    bool rightDirection = true;
    
    pair<int, int> numXY = {0, 0};
    
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        if (i == num) numXY = {x, y};
        //if (y < 0 || y >= 100 || x < 0 || x >= 100) break;

        v[x][y] = i;
        if (rightDirection) {
            if (i % w == 0) {
                rightDirection = false;
                x++;
            }
            else y++;
        }
        else {
            if (i % w == 0) {
                rightDirection = true;
                x++;
            }
            else y--;
        }
    }
    
    x = numXY.first;
    y = numXY.second;
    while (x < 100 && v[x][y] != 0) {
        x++;
        answer++;
    }
    return answer;
}