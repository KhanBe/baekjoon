#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	vector<int> data;

	int answer = 0;
	bool plus = true;

	string s = "";
	cin >> s;
	s += '@';

	int temp = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '-' || s[i] == '+' || s[i] == '@') {
			temp = plus ? temp : -temp;
			data.push_back(temp);
			temp = 0;


			if (s[i] == '-') plus = false;
			else if (s[i] == '+') continue;
		}

		else {
			temp *= 10;
			temp += s[i] - '0';
		}
	}

	//sort(data.begin(), data.end());

	//for (auto d : data) cout << d << " ";

	for (auto d : data) answer += d;
	cout << answer;
	return 0;
}