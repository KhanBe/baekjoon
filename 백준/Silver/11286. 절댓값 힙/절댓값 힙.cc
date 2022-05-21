#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) return a > b;
		else return abs(a) > abs(b);
	}
};
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	priority_queue<int, vector<int>, cmp> pq;

	int n, command;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> command;
		if (command != 0) pq.push(command);//값넣기

		else {// 0일경우
			if (pq.empty()) cout << "0\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
	}
}