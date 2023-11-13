#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct compare {
	bool operator()(string &a, string &b) {
		return a > b;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	map<string, string, greater<>> work;

	int n = 0;
	cin >> n;


	for (int i = 0; i < n; i++) {
		string name = "";
		string state = "";
		cin >> name >> state;

		work[name] = state;
	}

	vector<string> data;
	for (auto w : work) {
		if (w.second == "enter") cout << w.first << "\n";
	}
	return 0;
}