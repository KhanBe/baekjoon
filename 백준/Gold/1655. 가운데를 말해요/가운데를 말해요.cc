#include<iostream>
#include<vector>

#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int> maxheap;
	priority_queue<int, vector<int>, greater<int>> minheap;

	int n, a;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;

		if (maxheap.size() == minheap.size()) maxheap.push(a);
		else minheap.push(a);

		if (!maxheap.empty() && !minheap.empty()) {
			if (maxheap.top() > minheap.top()) {
				int maxtemp = maxheap.top();
				int mintemp = minheap.top();

				maxheap.pop();
				minheap.pop();

				maxheap.push(mintemp);
				minheap.push(maxtemp);
			}
		}

		cout << maxheap.top() << "\n";
	}
	return 0;
}