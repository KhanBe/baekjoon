#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int answer = 0;
	int n, k;
	cin >> n >> k;

	vector<int> arr;

	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}

	int point = 0;
	int sum = 0;
	for (int i = point; i < point + k; i++) {//초기배열
		sum += arr[i];
	}
	answer = sum;

	for (point = 0; point < n - k; point++) {
		sum -= arr[point];
		sum += arr[point + k];
		if (answer < sum) answer = sum;
	}
	cout << answer;
}