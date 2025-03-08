#include <iostream>
#include <vector>

using namespace std;

int N, S;
int answer = 0;
vector<int> arr;
int visited[21] = {0, };

void dfs(int res) {
	if (res == S) answer++;

	for (int i = 0; i < N; i++) {
		if (visited[i]) break;

		visited[i] = true;
		dfs(res + arr[i]);
		visited[i] = false; 
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	dfs(0);

	if (S == 0) answer--;
	cout << answer;
	return 0;
}