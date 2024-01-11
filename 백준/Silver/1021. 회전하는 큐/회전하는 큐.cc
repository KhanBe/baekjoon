#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	deque<int> d;

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) d.push_back(i + 1);
	
	int index = 0;
	int answer = 0;
	for (int i = 0; i < m; i++) {
		int num = 0;
		cin >> num;

		for (int j = 0; j < d.size(); j++) {//인덱스 찾기
			if (d[j] == num) {
				index = j;
				break;
			}
		}

		if ((d.size() / 2) < index) {//중간보다 뒤쪽이면
			while (1) {
				if (d[0] == num) {
					d.pop_front();
					break;
				}
				int temp = d.back();
				d.pop_back();
				d.push_front(temp);
				answer++;
			}
		}
		else {
			while (1) {
				if (d[0] == num) {
					d.pop_front();
					break;
				}
				int temp = d.front();
				d.pop_front();
				d.push_back(temp);
				answer++;
			}
		}
	}
	cout << answer;
	return 0;
}