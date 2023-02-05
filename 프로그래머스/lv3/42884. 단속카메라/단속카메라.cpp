#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    int start = routes[0][1];
    
    sort(routes.begin(), routes.end());
    
    //for (auto r : routes) cout << r[0] << " : " << r[1] << "\n";

    for (int i = 0; i < routes.size(); i++) {
        if (start >= routes[i][0]) {
            start = min(routes[i][1], start);
        }
        else {
            answer++;
            start = routes[i][1];
        }
    }
    return answer;
}