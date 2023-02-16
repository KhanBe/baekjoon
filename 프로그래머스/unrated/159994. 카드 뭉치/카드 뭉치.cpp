#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    queue<string> q1;
    queue<string> q2;
    
    for (auto c1 : cards1) q1.push(c1);
    for (auto c2 : cards2) q2.push(c2);
    
    int goal_index = 0;
    int q1_index = 0;
    int q2_index = 0;
    while (goal_index != goal.size()) {
        if (q1.front() == goal[goal_index]) {
            q1.pop();
            goal_index++;
        }
        else if (q2.front() == goal[goal_index]) {
            q2.pop();
            goal_index++;
        }
        
        else return "No";
    }
    return "Yes";
}