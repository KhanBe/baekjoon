#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	priority_queue<int> pq;

	int n;
	cin >> n;

	int command;
	for (int i = 0; i < n; i++) {
		cin >> command;
		if (command == 0) {
			if (pq.empty() == 1) cout << "0\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else pq.push(command);
	}
}