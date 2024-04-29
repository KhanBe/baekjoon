#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> st;
    
    for (auto a : arr) {
        if (!st.empty()) {
            int t = st.top();
            if (t == a) continue;
            else st.push(a);
        }
        else st.push(a);
    }
    while (!st.empty()) {
        int t = st.top();
        answer.push_back(t);
        st.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer;
}