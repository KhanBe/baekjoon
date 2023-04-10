#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> arr(N, 0);

	for (int i = 0; i < N; i++) cin >> arr[i];

	sort(arr.begin(), arr.end());

	int start = 0, end = N - 1;
	int min = abs(arr[0] + arr[N - 1]);
	int answer1 = arr[0], answer2 = arr[N - 1];

	while (start < end) {
		int sum = arr[start] + arr[end];//여기를 절대값으로 안함

		if (min > abs(sum)) {
			min = abs(sum);
			answer1 = arr[start];
			answer2 = arr[end];

			if (sum == 0) break;
		}

		if (sum < 0) start++;//sum이 음수냐 양수냐로 index변경
		else end--;
	}

	cout << answer1 << " " << answer2;
}