#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	int num;

	int n, m;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		cout << upper_bound(v.begin(), v.end(), num) - lower_bound(v.begin(), v.end(), num) << " ";
	}
	//이함수들을 쓰기전에 정렬 필수
	//upper_bound는 num을 초과한 인덱스를 반환
	//lower_bound는 num이 처음나오는 인덱스 반환
	//upper - lower 해주면 결국 num개수를 알 수 있다.
}