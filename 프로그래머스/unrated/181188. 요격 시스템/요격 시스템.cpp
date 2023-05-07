#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(vector<int> & t1, vector<int> & t2) {
    return t1[1] < t2[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    vector<bool> visited(targets.size());
    
    sort(targets.begin(), targets.end(), cmp);
    for (int i = 0; i < targets.size(); i++) {
        
        if (!visited[i]) {
            answer++;
            int e = targets[i][1];
            
            for (int j = i + 1; j < targets.size(); j++) {
                if (targets[j][0] < e) {
                    visited[j] = true;
                }
                else break;
            }
        } 
    }
    return answer;
}