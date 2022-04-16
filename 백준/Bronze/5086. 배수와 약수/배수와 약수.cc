#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int a, b;
	
	while (1) {
		cin >> a >> b;
		if (a == b) break; //조건으로 a와 b는 항상 다르니 (0 0)일때는 이렇게 조건으로

		if (a % b == 0) cout << "multiple" << "\n";
		else if (b % a == 0) cout << "factor" << "\n";
		else cout << "neither" << "\n";
	}
}