#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    stack<string> st;
    
    for (int i = 0; i < s.length(); i++) {
        int pivot = s[i];
        if (pivot == '(') {
            st.push("(");
        }
        else if (pivot == ')') {
            if (!st.empty() && st.top() == "(" ){
                st.pop();
            }
            else return false;
        }
    }
    
    if (!st.empty()) answer = false;
    return answer;
}