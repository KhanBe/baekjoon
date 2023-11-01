#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int row = 0, column = 0;
	int max = 0;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int num = 0;
			cin >> num;
			if (max < num) {
				max = num;
				row = i;
				column = j;
			}
		}
	}
	cout << max << "\n" << row + 1 << " " << column + 1;
}