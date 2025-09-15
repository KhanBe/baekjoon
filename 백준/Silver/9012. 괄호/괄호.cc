#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

vector<string> answer;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T = 0;
    string temp = "";

    cin >> T;  
    for (int i = 0; i < T; i++) {
        cin >> temp;

        stack<char> s;

        for (int j = 0; j < temp.size(); j++){
            if (temp[j] == '(') {
                s.push(temp[j]);
            }
            else if (temp[j] == ')') {
                if (s.size() == 0) {
                    s.push(temp[j]);
                    break;
                }
                else s.pop();
            }
        }
        answer.push_back((s.empty() ? "YES" : "NO"));
    }
    
    for (auto a : answer) cout << a << "\n";

    return 0;
}