#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B;
	cin >> A >> B;

	vector<int> arr(A + B, 0);

	for (int i = 0; i < A + B; i++) cin >> arr[i];

	sort(arr.begin(), arr.end());

	for (auto a : arr) cout << a << " ";
}