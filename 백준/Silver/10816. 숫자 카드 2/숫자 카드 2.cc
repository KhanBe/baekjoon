#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int card[20000005];
int N = 0, M = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp = 0;
		cin >> temp;
		card[10000000 + temp]++;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int temp = 0;
		cin >> temp;
		cout << card[10000000 + temp] << " ";
	}
}