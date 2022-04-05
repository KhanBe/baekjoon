#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

int main(void) {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int test;
	cin >> test;

	int answer = 0;
	int n;
	int m;
	int num;
	for (int i = 0; i < test; i++) {
		queue<pair<int, int>> q;
		priority_queue<int> prio;
		answer = 0;
        
		cin >> n >> m;
		for (int j = 0; j < n; j++) {
			cin >> num;
			prio.push(num);
			q.push({ num, j });
		}
		while (1) {
			if (q.front().first != prio.top()) {
				q.push(q.front());
				q.pop();
			}
			else {
				answer++;
				if (q.front().second == m) break;
				prio.pop();
				q.pop();
			}
		}
		cout << answer << "\n";
	}
}