#include <string>
#include <vector>

using namespace std;

int visited[8] = {0,};
int answer = -1;

void dfs (int depth, vector<vector<int>> dungeons, int k) {
    
    if (answer < depth) answer = depth;
    
    for (int i =0;i <dungeons.size(); i++) {
        if (visited[i]) continue;
        
        if (dungeons[i][0] <= k) {
            visited[i] = true;
            dfs(depth + 1,dungeons, k - dungeons[i][1]);
            visited[i] = false;   
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    
    dfs(0, dungeons, k);

    
    return answer;
}