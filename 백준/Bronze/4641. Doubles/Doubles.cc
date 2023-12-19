#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool board[16][16];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	
	int num;
	int count = 0;
	vector <int> v;

	while (1) {
		cin >> num;

		if (num == -1) {
			break;
		}
		if (num == 0) {
			for (int i = 0; i < v.size(); ++i) {
				for (int j = 0; j < v.size(); ++j) {
					if (v[j] * 2 == v[i]) {
						++count;
					}
				}
			}
			cout << count << endl;
			count = 0;
			v.clear();
		}
		else {
			v.push_back(num);
		}
	}

	return 0;
}