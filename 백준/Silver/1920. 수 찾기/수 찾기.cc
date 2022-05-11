#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	map<int, bool> map;

	int num;

	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		map.insert({ num, true });
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		if (map.count(num)) cout << "1\n";
		else cout << "0\n";
	}
}