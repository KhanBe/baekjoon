#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

vector<string> answer;
int dp[101][100001];
int N, K;
int W, V;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    vector<pair<int, int>> items(N + 1);

    //입력
    for (int i =1;i <= N; i++) {
        cin >> W >> V;
        items[i] = {W, V};
    }

    for (int i = 1; i <= N; i++) {
        int iw = items[i].first;
        int iv = items[i].second;
        for (int w = 1; w <= K; w++) { 
            //무게초과시
            if (w < iw) dp[i][w] = dp[i - 1][w];
            else dp[i][w] = max(dp[i -1][w], dp[i -1][w - iw] + iv);
        }
    }

    cout << dp[N][K];
    return 0;
}