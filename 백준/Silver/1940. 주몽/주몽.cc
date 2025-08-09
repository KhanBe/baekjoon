#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int answer = 0;
    int arr[15001] = {0,};
    int n = 0, m = 0;
    cin >> n;
    cin >> m;

    for (int i =1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <n; i++) {
        if (m <= arr[i]) continue;

        for (int j = i + 1; j <=n; j++) {
            if (m <= arr[j]) continue;

            if (arr[i] + arr[j] == m) answer++;
        }
    }
    
    cout << answer;
    
    return 0;
}