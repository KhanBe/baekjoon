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

int lcm(int a, int b) {//최소공배수는 공식으로 알고있으면된다.
	return a * b / gcd(a, b);
}

int main(void) {
	int a, b;
	cin >> a >> b;

	cout << gcd(a, b) << "\n" << lcm(a, b) << "\n";
}