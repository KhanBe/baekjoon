#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int board[101][101];
bool visited[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, answer = 0, area = 0;

void bfs(int x, int y, int Height)
{
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    visited[x][y] = true;

    while (!q.empty())
    {
        int X = q.front().first;
        int Y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nX = X + dx[i];
            int nY = Y + dy[i];
            if (!(0 <= nX && nX < n) || !(0 <= nY && nY < n))
                continue;
            if (!visited[nX][nY] && board[nX][nY] > Height)
            {
                q.push(make_pair(nX, nY));
                visited[nX][nY] = true;
            }
        }
    }
    area++;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int MaxHeight = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            MaxHeight = MaxHeight < board[i][j] ? board[i][j] : MaxHeight;
        }
    }

    for (int h = 0; h <= MaxHeight; h++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && board[i][j] > h)
                {
                    bfs(i, j, h);
                }
            }
        }
        //초기화
        answer = area > answer ? area : answer;
        area = 0;
        for (int i = 0 ; i < n; i++) {
            for (int j = 0 ; j < n; j++) {
                visited[i][j] = false;
            }
        }
    }

    cout << answer;
    return 0;
}
//Control + Option + B
//Control + Option + N
