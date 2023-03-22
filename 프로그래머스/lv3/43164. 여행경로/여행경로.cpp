#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visited(10000, false);
vector<string> answer;
int cnt = 0;
bool flag = false;

bool compare (vector<string> v1, vector<string> v2) {
    if (v1[0] == v2[0]) return v1[1] < v2[1];
    return v1[0] < v2[0]; 
}

void dfs (string start, vector<vector<string>> tickets) {
    if (cnt == tickets.size()) flag = true;
    
    answer.push_back(start);
    
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == start && !visited[i]) {
            visited[i] = true;
            cnt++;
            
            dfs(tickets[i][1], tickets);
            
            if (!flag) {
                answer.pop_back();
                visited[i] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end(), compare);
    
    dfs("ICN", tickets);
    
    return answer;
}