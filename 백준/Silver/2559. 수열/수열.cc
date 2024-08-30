#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int arr[100000] = { 0, };
int N = 0, K = 0;
int answer = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < K; i++) {
		answer += arr[i];
	}

	int p2 = K;
	int temp = answer;
	for (int p1 = 0; p2 < N; p1++, p2++) {
		temp = temp - arr[p1] + arr[p2];
		answer = max(answer, temp);
	}
	cout << answer;
}
