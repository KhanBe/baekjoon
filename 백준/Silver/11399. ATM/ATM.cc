#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int answer = 0;
	vector<int> data;
	map<int, int> m;

	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int time = 0;
		cin >> time;
		data.push_back(time);
	}
	sort(data.begin(), data.end());

	int waiting = 0;
	for (int i = 0; i < n; i++) {
		waiting += data[i];
		answer += waiting;
	}
	cout << answer;
	return 0;
}