#include <iostream>

using namespace std;

int get_gcd(int a, int b) {//최대공약수 구하는 함수
	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main(void) {// 기약분수 = 최대공약수로 나누면됨
	int n;
	cin >> n;

	int a;
	cin >> a;

	int b;
	int gcd;
	for (int i = 0; i < n - 1; i++) {
		cin >> b;
		gcd = get_gcd(a, b);
		cout << a / gcd << "/" << b / gcd << "\n";
	}
}