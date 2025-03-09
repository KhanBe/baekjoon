#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 987654321

using namespace std;

int N = 0, M = 0;
vector<int> v;
vector<int> temp;
bool visited[10] = { 0, };

void dfs(int count) {
	if (M == count) {
		for (auto ele : temp) cout << ele << " ";
		cout << "\n";
	}

	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		
		temp.push_back(v[i]);
		visited[i] = true;
		dfs(count + 1);
		temp.pop_back();
		visited[i] = false;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int temp = 0;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());


	dfs(0);


	return 0;
}