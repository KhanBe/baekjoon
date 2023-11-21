#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	stack<int> st;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		switch (num) {
		case 1: {
			int input = 0;
			cin >> input;
			st.push(input);
			break;
		}
		case 2: {
			int output = -1;
			if (!st.empty()) {
				output = st.top();
				st.pop();
			}
			cout << output << "\n";
			break;
		}
		case 3:
			cout << st.size() << "\n";
			break;
		case 4:
			if (st.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
			break;
		case 5: {
			int output = -1;
			if (!st.empty()) {
				output = st.top();
			}
			cout << output << "\n";
			break;
		}
		default:
			break;
		}
	}


	return 0;
}