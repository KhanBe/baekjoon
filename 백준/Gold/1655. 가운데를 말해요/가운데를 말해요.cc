#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;

	int n;
	cin >> n;

	int num = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (max_heap.size() == min_heap.size()) max_heap.push(num);
		else min_heap.push(num);

		int temp;
		if (!min_heap.empty()) {
			if (min_heap.top() < max_heap.top()) { // swap
				temp = min_heap.top();
				min_heap.pop();
				min_heap.push(max_heap.top());
				max_heap.pop();
				max_heap.push(temp);
			}
		}

		cout << max_heap.top() << "\n";
	}
}
// reference : https://yabmoons.tistory.com/478