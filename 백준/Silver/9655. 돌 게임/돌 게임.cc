#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	deque<int> d;

	int n;
	cin >> n;

	if (n % 2 == 1) cout << "SK";
	else cout << "CY";

	return 0;
}