#include <iostream>

using namespace std;

int factorial(int a) {
	if (a <= 1) return 1;
	return a * factorial(a - 1);
}

int main(void) {//이항계수 공식 = n! / (k!*(n-k)!)
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	int tc;
	cin >> tc;

	int n, k;
	for (int i = 0; i < tc; i++) {
		long long int answer = 1;
		cin >> n >> k;
		for (int j = 0; j < n; j++) {
			answer *= k - j;
			answer /= 1 + j;
		}
		cout << answer << "\n";
	}
}