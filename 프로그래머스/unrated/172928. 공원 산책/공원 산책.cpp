#include <string>
#include <vector>
#include <iostream>

using namespace std;

int x = 0;
int y = 0;
int H = 0;
int W = 0;

void get_position(vector<string> park) {
    for (int i = 0; i < park.size(); i++) {//좌표따기
        for (int j = 0; j < park[i].length(); j++) {
            if (park[i][j] == 'S') {
                y = i;
                x = j;
                return ;
            }
        }
    }
}

void move(vector<string> park, vector<string> routes) {
    for (auto r : routes) {
        char dir = r[0];
        int dis = r[2] - '0';
        bool error = false;
        
        int i = 0;
        if (dir == 'E') {
            for (i = 1; i <= dis; i++) {
                if (W <= (x + i)) { error = true; break; }
                if (park[y][x + i] == 'X') { error = true; break; }
            }
            if (!error) x = x + dis;
        }
        else if (dir == 'W') {
            for (i = 1; i <= dis; i++) {
                if (0 > (x - i)) { error = true; break; }
                if (park[y][x - i] == 'X') { error = true; break; }
            }
            if (!error) x = x - dis;
        }
        else if (dir == 'S') {
            for (i = 1; i <= dis; i++) {
                if (H <= (y + i)) { error = true; break; }
                if (park[y + i][x] == 'X') { error = true; break; }
            }
            if (!error) y = y + dis;
        }
        else if (dir == 'N') {
            for (i = 1; i <= dis; i++) {
                if (0 > (y - i)) { error = true; break; }
                if (park[y - i][x] == 'X') { error = true; break; }
            }
            if (!error) y = y - dis;
        }
        
    }
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    //get map size
    H = park.size();
    W = park[0].length();
    
    get_position(park);
    move(park, routes);
    
    answer.push_back(y);
    answer.push_back(x);
    return answer;
}