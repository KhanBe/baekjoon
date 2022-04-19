#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //각 종류+1만큼 곱하고 -1 = (kind + 1)*(kind + 1)...(kind + 1) - 1
	map<string, int> m;
	int answer = 1;

	int n;
	cin >> n;

	int count = 0;
	string clothes;
	string kinds;
	for (int i = 0; i < n; i++) {
		cin >> count;
		for (int j = 0; j < count; j++) {
			cin >> clothes;
			cin >> kinds;
			m[kinds] += 1;//map에 값 넣기
		}

		for (auto iter = m.begin(); iter != m.end(); iter++) {//map for문
			answer *= iter->second + 1;
		}
		cout << answer - 1 << "\n";//출력
		answer = 1;//초기화
		m.clear();
	}
}