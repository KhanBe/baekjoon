#include <iostream>
#include <vector>

using namespace std;

int N = 0, M = 0;
int answer = 0;
vector<int> v(1000001);

void binary_search(int start, int end) {
    if (start > end) return;

    long long mid = (start + end) / 2;
    long long sum = 0;
    
    for (int i =0;i < N; i++) {
        if (0 < v[i] - mid) {
            sum += v[i] - mid;
        }
    }
    if (sum >= M) {
        answer = mid;
        binary_search(mid + 1, end);
    }
    else {
        binary_search(start, mid - 1);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tree_max = 0;

    cin >> N >> M;
    for (int i =0; i < N; i++) {
        cin >> v[i];
        tree_max = max(v[i], tree_max);
    }

    binary_search(1, tree_max);

    cout <<answer;


    return 0;
}