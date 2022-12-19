#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    
    for (int i = 0; i < s.length(); i++) {
        stack<char> st;
        
        for (auto c : s) {
            if (c == '[' || c == '(' || c == '{') {
                st.push(c);
            }
            else {
                if (st.top() == '[' && c == ']' ||
                    st.top() == '(' && c == ')' ||
                    st.top() == '{' && c == '}') {
                    st.pop();
                }
                else st.push(c);
            }
        }
        if (st.empty()) answer++;
        
        while (!st.empty()) st.pop();
        
        char temp = s[0];
        s.erase(0, 1);
        s += temp;
    }
    return answer;
}