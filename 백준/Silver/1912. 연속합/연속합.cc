#include <iostream>
#include <vector>

using namespace std;

int arr[100001] = { 0, };
int arr_sum[100001] = { 0, };

int getMax(int a, int b) {
	if (a > b) return a;
	return b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int max = 0;
	int n = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	// arr_sum settings
	max = arr[1];
	arr_sum[1] = arr[1];
	for (int i = 2; i <= n; i++) {
		arr_sum[i] = getMax(arr_sum[i - 1] + arr[i], arr[i]);
		max = getMax(arr_sum[i], max);
	}
	
	cout << max;
	return 0;
}
