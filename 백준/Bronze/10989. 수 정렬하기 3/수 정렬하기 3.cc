#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[10001] = { 0, };

	int n;
	cin >> n;

	int num = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr[num]++;
	}

	for (int i = 1; i <= 10000; i++) {
		while (0 < arr[i]) {
			cout << i << "\n";
			arr[i]--;
		}
	}
}