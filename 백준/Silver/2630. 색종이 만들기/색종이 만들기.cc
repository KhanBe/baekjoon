#include <iostream>
#include <vector>

using namespace std;

int blue, white;
//함수의 프로토타입 / vector, int 파라미터로 받았을 때의 형태
vector<vector<int>> input(vector<vector<int>> &map, int &N)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];
    return map;
}

void dfs(vector<vector<int>> &map, int x, int y, int size)
{
    int first = map[x][y];
    bool flag = true;

    for(int i = x; i < x + size; i++){
        for(int j = y; j <y + size;j++){
            if (first != map[i][j]){
                flag = false;
                break;
            }
        }
        if (!flag) break;
    }

    if (flag){
        if (map[x][y] == 1) {blue++; return;}
        if (map[x][y] == 0) {white++; return;}
    }
    
    dfs(map, x, y, size / 2);
    dfs(map, x, y + size / 2, size / 2);
    dfs(map, x + size / 2, y, size / 2);
    dfs(map, x + size / 2, y + size / 2, size / 2);
}

int main(void)
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<vector<int> > map(N, vector<int>(N, 0));

    map = input(map, N);
    
    dfs(map, 0, 0, N);

    cout << white << "\n" << blue << "\n"; 
}