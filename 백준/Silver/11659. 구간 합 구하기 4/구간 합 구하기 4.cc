#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[100001];
    
    int n = 0, m = 0;
    cin >> n >> m;

    int temp = 0;
    for (int i = 1; i <= n ; i++){
        cin >> temp;
        arr[i] = arr[i - 1] + temp;
    }
    
    int a = 0, b = 0;
    for (int i =0;i <m;i++) {
        cin >> a >> b;
        cout << arr[b] - arr[a - 1] << "\n";
    }
    
    return 0;
}