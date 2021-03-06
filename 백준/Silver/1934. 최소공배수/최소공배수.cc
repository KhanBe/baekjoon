#include <iostream>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main(void) {
	int n;
	cin >> n;

	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		cout << lcm(a, b) << "\n";
	}
}