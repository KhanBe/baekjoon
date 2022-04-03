#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	stack<char> st;
	string s;
	char c;

	while (1) {
	
		getline(cin, s); // cin >> s;로 하면 출력이 여러번 된다.

		if (s.at(0) == '.') break;

		bool flag = true;

		for (int i = 0; i < s.length() - 1; i++) {
			c = s.at(i);

			if (c == '(' || c == '[') st.push(c);

			else if (c == ')') {//empty()를 안써주면 top()입력시 스택범위를 벗어나는 문제가 생길 수 있다.(size가 0일때)
				if (!st.empty() && st.top() == '(') st.pop();
				else {
					flag = false;
					break;
				}
			}

			else if (c == ']') {
				if (!st.empty() && st.top() == '[') st.pop();
				else {
					flag = false;
					break;
				}
			}
		}


		if (flag && st.empty()) cout << "yes" << endl;
		else cout << "no" << endl;

		while (!st.empty()) st.pop();
	}
}