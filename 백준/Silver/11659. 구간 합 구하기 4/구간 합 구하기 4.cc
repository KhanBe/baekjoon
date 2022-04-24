#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	int sum = 0;
	vector<int> sums;

	int n, m;
	cin >> n >> m;
	

	int num = 0;
	for (int i = 0; i < n; i++) { //O(n)
		cin >> num;
		sum += num;
		sums.push_back(sum);
	}

	// 원래는 그냥 각 숫자들의 배열로 합을 구함O(n^2)
	// 시간 초과로 아예 합들의 배열로 바꿔 O(n)으로 구현해봄
	int a, b;
	for (int i = 0; i < m; i++) {
		sum = 0;
		cin >> a >> b;

		sum = sums[b - 1];
		if (a != 1) sum -= sums[a - 2];

		cout << sum << "\n";
	}
}