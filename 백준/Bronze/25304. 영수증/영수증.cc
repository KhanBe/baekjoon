#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int total, n, price, count = 0;
    int answer = 0;

    cin >> total;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> price >> count;
        answer += price * count;
    }
    
    if (answer == total) cout << "Yes";
    else cout << "No";


    return 0;
}