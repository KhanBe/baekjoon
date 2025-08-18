#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int arr[100001];
    int dp[100001];

    int n = 0;
    cin >> n;

    for (int i =1;i <=n;i++) {
        cin >> arr[i];
    }

    
    dp[1] = arr[1];

    int max_answer = -987654321;
    for (int i=1;i<=n;i++) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);

        max_answer = max_answer < dp[i] ? dp[i] : max_answer;
    }

    cout << max_answer;
    return 0;
}