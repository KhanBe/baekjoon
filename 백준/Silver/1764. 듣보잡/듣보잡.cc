#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int answer = 0;
	map<string, bool> map;

	int n, m;
	cin >> n >> m;

	string name;
	for (int i = 0; i < n; i++) {
		cin >> name;
		map.insert({ name, false });
	}
	for (int i = 0; i < m; i++) {
		cin >> name;
		if (map.find(name) != map.end()) {
			map[name] = true;
			answer++;
		}
	}

	cout << answer << "\n";
	for (auto iter = map.begin(); iter != map.end(); iter++) {
		if (iter->second) cout << iter->first << "\n";
	}
	//find()는 key를 가진 요소를 발견하면 값 리턴
	//아니면 end() 리턴
}