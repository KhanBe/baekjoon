#include <iostream>
#include <vector>
#include <string>
using namespace std;

//bool prime[100000000];
int length = 0;

bool isPrime(int n) {
	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0) return false;
	}
	return true;
}
void dfs(int n) {
	string s = to_string(n);

	if (isPrime(n)) {
		if (s.length() == length) {
			cout << n << "\n";
			return;
		}
		for (int i = 1; i <= 9; i += 2) {
			dfs(n * 10 + i);
		}  
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N; 
	length = N;

	//for (int i = 0; i < N; i++) prime[i] = true;

	//에라토스테네스는 메모리 제한에 걸림
	/*prime[0] = prime[1] = false;
	for (int i = 2; i * i < N; i++) {
		if (prime[i]) {
			for (int j = i * i; j < N; j += i) {
				prime[j] = false;
			}
		}
	}*/

	dfs(2);
	dfs(3);
	dfs(5);
	dfs(7);
}