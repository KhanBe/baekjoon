#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair <int, int>> tree[100001];

int visited[100001];
int end_node = 0;
int answer = 0;

void dfs(int node, int distance) {

    if (visited[node]) return;
    visited[node] = true;

    if (answer < distance) {// 길이와 마지막노드 갱신
        answer = distance;
        end_node = node;
    }
    
    for (int i = 0;i < tree[node].size();i++){
        int next = tree[node][i].first;
        int next_dis = tree[node][i].second;
        dfs(next, next_dis + distance);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    cin >> n;

    int node = 0;
    for (int i = 0;i < n;i++){
        cin >> node;

        int another, distance = 0;
        while (1) {
            cin >> another;
            if (another == -1) break;
            cin >> distance;
            tree[node].push_back({another, distance});
        }
    }
    
    dfs(1, 0);

    memset(visited, false, sizeof(visited));

    answer = 0;
    dfs(end_node, 0);

    cout << answer << "\n";
    
    return 0;
}