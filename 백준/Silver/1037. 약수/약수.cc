#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	vector<int> arr;

	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}
    // 벡터 stl에서 많이 알아보기;
	sort(arr.begin(), arr.end()); // begin(), end()는 주소 참조이고
	int answer = arr.front() * arr.back();// 여기는 원소 참조이다.

	cout << answer << "\n";
}