#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int startIdx = 0;
	//입력
	string s = "";
	cin >> s;
	string temp = "";
	for (int i = 0; i < s.size(); i++) {
		temp += s[i];
		if (temp.size() == 10 || (i == s.size() -1)) {
			cout << temp << "\n";
			temp = "";
		}
	}
	return 0;
}