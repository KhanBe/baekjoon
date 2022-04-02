#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int k;
	string value;
	char c;

	cin >> k;

	stack<char> st;

	for (int i = 0; i < k; i++) {
		cin >> value;

		for (int j = 0; j < value.length(); j++) {
			c = value.at(j);

			if (c == '(') st.push(c);
			else {
				if (st.size() == 0) {
					st.push(c);
					break;
				}

				else st.pop();
			}
		}

		if (st.size() == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
		
		while (!st.empty()) st.pop(); // c++은 clear가 없다
	}

}