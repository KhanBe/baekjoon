#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	map<int, int> map;

	int a, b;
	cin >> a >> b;

	int num;
	for (int i = 0; i < a + b; i++) {
		cin >> num;
		if (map.find(num) != map.end()) map.erase(num);
		else map.insert({ num, 1 });
	}
	
	int answer = map.size();

	cout << answer;
	//find함수는 찾는key가 없을 경우 end()주소값을 반환한다.
}