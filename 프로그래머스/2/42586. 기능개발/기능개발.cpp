#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> deadline;
    
    for (int i = 0; i < progresses.size(); i++) {
        int progress = progresses[i];
        int speed = speeds[i];
        int getDay = 0;
        while (progress < 100) {
            progress += speed;
            getDay++;
        }
        deadline.push_back(getDay);
    }
    
    stack<int> st;
    st.push(deadline[0]);
    int pivot = st.top();
    for (int i = 1; i < deadline.size(); i++) {
        if (pivot < deadline[i]) {
            answer.push_back(st.size());
            while (!st.empty()) st.pop();
        
            pivot = deadline[i];
        }
        st.push(deadline[i]);
    }
    
    answer.push_back(st.size());
    //for (auto d : answer) cout << d << " ";
    return answer;
}