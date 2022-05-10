#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	map<string, bool> map;

	
	int answer = 0;
	string s;

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		map.insert({ s, true });
	}

	for (int i = 0; i < m; i++) {
		cin >> s;
		if (map.count(s)) answer++;
	}

	cout << answer;
}