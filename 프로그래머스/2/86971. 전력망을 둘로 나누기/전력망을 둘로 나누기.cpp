#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int visited[101];
vector<int> node[101];

int bfs(int start, int disA, int disB) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int count = 1;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i =0;i <node[cur].size(); i++) {
            int next = node[cur][i];
            
            if (visited[next]) continue;
            if ((cur == disA && next == disB) ||
                (cur == disB && next == disA)) continue;
            
            count++;
            visited[next] = true;
            q.push(next);
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    
    for (int i =0;i <wires.size(); i++) {//입력
        int from = wires[i][0];
        int to = wires[i][1];
        node[from].push_back(to);
        node[to].push_back(from);
    } 
    
    for (int i = 0; i < wires.size(); i++) {
        int a = bfs(wires[i][0], wires[i][0], wires[i][1]);
        int b = bfs(wires[i][1], wires[i][0], wires[i][1]);
        //cout << a << " " << b << "\n";
        
        for (int j =1;j <=n;j++) visited[j] = false;
        answer = min(answer, abs(b - a));
    }
    
    return answer;
}