#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    stack<int> st;
    
    for (auto i : ingredient) {
        st.push(i);
        if (st.top() == 1) {
            st.pop();
            if (!st.empty() && st.top() == 3) {
                st.pop();
                if (!st.empty() && st.top() == 2) {
                    st.pop();
                    if (!st.empty() && st.top() == 1) {
                        st.pop();
                        answer++;
                    }
                    else {
                        st.push(2);
                        st.push(3);
                        st.push(1);
                    }
                }
                else {
                    st.push(3);
                    st.push(1);
                }
            }
            else st.push(1);
        }
    }
    return answer;
}