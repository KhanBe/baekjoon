#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N[91];
    int answer = 0;
    int n = 0;

    cin >> n;
    N[1] = 1;
    N[2] = 1;
    N[3] = 2;

    for (int i =4;i <=n; i++) {
        N[i] = N[i - 2] + N[i - 1];
    }




    cout << N[n];
    
    return 0;
}