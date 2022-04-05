#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
	queue<int> q;
	int temp = 0;
	vector<int> answer;

	int n;
	cin >> n;
	int k;
	cin >> k;

	for (int i = 1; i <= n; i++) q.push(i);

	while (!q.empty()) {
		for (int i = 0; i < k - 1; i++) {//마지막으로 
			temp = q.front();
			q.pop();
			q.push(temp);
		}
		answer.push_back(q.front());//출력백터에 담기
		q.pop();//지우기
	}
    //출력
	cout << "<";
	for (int i = 0; i < n; i++) {
		if (i == n - 1) cout << answer[i];
		else cout << answer[i] << ", ";
	}
	cout << ">\n";
}