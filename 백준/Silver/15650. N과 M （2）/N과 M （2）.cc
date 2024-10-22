#include <iostream>
#include <vector>

using namespace std;

int N = 0;
int M = 0;
int visited[10] = { 0,};
vector<int> v(1);

void recursive(int count) {
	if (count != 0) {
		if (v[count - 1] > v[count]) return;
	}

	if (count == M) {//출력
		for (int i = 1; i <= count; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;

		visited[i] = true;
		v.push_back(i);
		recursive(count + 1);
		visited[i] = false;
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
		
	recursive(0);

	return 0;
}