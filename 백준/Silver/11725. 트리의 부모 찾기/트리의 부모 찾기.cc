#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[100001];
int visited[100001], parent[100001];

void dfs(int node) {
    visited[node] = true;
    for (int i = 0;i < tree[node].size();i++){
        int next = tree[node][i];
        if (!visited[next]) {
            parent[next] = node;
            dfs(next);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    cin >> n;

    int a,b = 0;    
    for (int i = 0;i < n - 1;i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    dfs(1);

    for (int i = 2;i <= n;i++) cout << parent[i] << "\n";
    
    return 0;
}