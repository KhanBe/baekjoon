#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	queue<int> q;

	int temp = 0;
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) q.push(i);

	while (1) {
		if (q.size() == 1) break;

		q.pop(); // 버리기

		if (q.size() == 1) break;

		temp = q.front(); //밑으로 옮기기
		q.pop();
		q.push(temp);
	}
	
	cout << q.front() << "\n";
}