#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	map<string, int> map;
	string arr[100001];

	int m, n;
	cin >> m >> n;

	string monster;
	for (int i = 0; i < m; i++) {
		cin >> monster;
		map.insert({ monster, i + 1 });
		arr[i] = monster;
	}
	string search;
	for (int i = 0; i < n; i++) {
		cin >> search;
		if (isdigit(search.at(0))) {
			int num = stoi(search);
			cout << arr[num - 1] << "\n";
		}
		else {
			cout << map[search] << "\n";
		}
	}
}