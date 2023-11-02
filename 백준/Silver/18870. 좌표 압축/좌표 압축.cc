#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> data;
	map<int, int> m;

	int n = 0;
	cin >> n;

	int num = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		data.push_back(num);
	}
	vector<int> data_temp(data);
	sort(data.begin(), data.end());

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (m.find(data[i]) == m.end()) m.insert({ data[i], count++ });
	}

	for (int i = 0; i < n; i++) {
		cout << m[data_temp[i]] << " ";
	}
	return 0;
}