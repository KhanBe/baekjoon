#include <iostream>

using namespace std;

int factorial(int a) {
	if (a <= 1) return 1;
	return a * factorial(a - 1);
}

int main(void) {//이항계수 공식 = n! / (k!*(n-k)!)
	int n, k;

	cin >> n >> k;

	cout << factorial(n) / (factorial(k) * factorial(n - k)) << "\n";
}