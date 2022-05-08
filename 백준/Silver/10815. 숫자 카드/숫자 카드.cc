#include <iostream>
#include <map>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	map<int, bool> map;

	int card;

	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> card;
		map.insert({ card, true });
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> card;
		if (map.find(card) != map.end()) cout << "1";
		else cout << "0";
		
		if (i != m - 1) cout << " ";
	}
}