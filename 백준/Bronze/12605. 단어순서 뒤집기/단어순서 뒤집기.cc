#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	
	int n;
	cin >> n;
	cin.ignore();//버퍼제거

	for (int i = 0; i < n; i++) {
		string s = "";
		getline(cin, s);//한줄 입력받기

		string temp = "";
		stringstream ss_temp(s);

		cout << "Case #" << i + 1 << ": ";
		string answer = "";
		while (ss_temp >> temp) {
			answer = temp + " " + answer;
		}
		cout << answer << "\n";
	}
	
	return 0;
}