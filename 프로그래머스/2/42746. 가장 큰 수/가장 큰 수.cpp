#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(const string &v1, const string &v2) {
	return v1 + v2 > v2 + v1;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> numberString;

	for (auto n : numbers) {
		numberString.push_back(to_string(n));
	}

	sort(numberString.begin(), numberString.end(), compare);

	for (auto n : numberString) {
		answer += n;
	}
	if (answer[0] == '0') answer = "0";

	return answer;
}