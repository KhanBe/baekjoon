#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	char data[5][16] = {0,};

	for (int i = 0; i < 5; i++) {
		string s = "";
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			data[i][j] = s[j];
		}
	}

	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 5; j++) {
			if (data[j][i] != NULL) cout << data[j][i];
		}
	}
}