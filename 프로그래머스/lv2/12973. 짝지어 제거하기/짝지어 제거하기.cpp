#include <iostream>
#include<string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> st;
    
    for (auto c : s) {
        if (!st.empty()) {
            if (c == st.top()) st.pop();
            else st.push(c);
        }
        else st.push(c);
    }
    
    return st.empty() ? 1 : 0;
}