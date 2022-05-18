#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	map<string, int> map;

	string str;
	cin >> str;

	string temp = "";
	for (int i = 0; i < str.length(); i++) {
		for (int j = 0; j < str.length() - i; j++) {
			temp = str.substr(j, i + 1);
			map.insert({ temp, 1 });
		}
	}
	cout << map.size();
    // 01 11 21 31 41
    // 02 12 22 32
    // 03 13 23
    // 04 14
    // 05
    // 위와같은 패턴을 가지고있다.
}