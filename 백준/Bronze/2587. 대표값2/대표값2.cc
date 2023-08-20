#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> v(5);

    int sum = 0;
    int mid = 0;

    for (int i = 0; i < 5; i++) {
        cin >> v[i];
        sum += v[i];
    }
    
    sort(v.begin(), v.end());

    mid = v[2];
    cout << sum / 5 << "\n" << mid;

    return 0;
}
//Control + Option + B
//Control + Option + N
