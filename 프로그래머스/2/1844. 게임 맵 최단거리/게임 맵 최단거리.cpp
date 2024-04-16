#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int solution(vector<vector<int> > maps) {
    int answer = -1;

    int m = maps.size();//가로
    int n = maps[0].size();// 세로
    vector<vector<int>> node(m, vector<int>(n, 0));
    node[0][0] = 1;

    queue<pair<int, int>> q;
    q.push({ 0, 0 });

    while (!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];

            //범위
            if (!(0 <= nextY && nextY <= m - 1) ||
                !(0 <= nextX && nextX <= n - 1)) continue;
            //벽
            if (maps[nextY][nextX] != 1 || node[nextY][nextX] != 0) continue;

            q.push({ nextY, nextX });
            node[nextY][nextX] = node[curY][curX] + 1;

            if (nextX == n - 1 && nextY == m - 1) {
                    //도착지
                return node[nextY][nextX];
            }
        }
        
    }
    return answer;
}