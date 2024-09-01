#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> arr;

void search(int start, int end, int target) {
	while (1) {
		if (start == end) {// 마지막 원소일 때
			if (arr[start] == target) cout << "1\n";
			else cout << "0\n";
			break;
		}
		int mid = (start + end) / 2;
		if (arr[mid] < target) {
			start = mid + 1;
		}
		else {
			end = mid;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0, M = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp = 0;
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	
	cin >> M;

	for (int i = 0; i < M; i++) {
		int t = 0;
		cin >> t;

		search(0, N - 1, t);
	}
}