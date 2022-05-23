#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> arr;
	vector<int> brr;

	int num;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		cin >> num;
		brr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	sort(brr.begin(), brr.end(), greater<int>());

	int answer = 0;
	for (int i = 0; i < n; i++) {
		answer += arr[i] * brr[i];
	}
	cout << answer;
}