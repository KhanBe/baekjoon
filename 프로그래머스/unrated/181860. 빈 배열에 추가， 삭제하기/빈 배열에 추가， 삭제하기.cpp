#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<bool> flag) {
    vector<int> answer;
    stack<int> s;
    
    for (int i = 0; i < arr.size(); i++) {
        if (flag[i]) {
            for (int j = 0; j < arr[i] * 2; j++) s.push(arr[i]);
        }
        else {
            for (int j = 0; j < arr[i]; j++) s.pop();
        }
    }

    while (!s.empty()) {
        int top = s.top();
        answer.push_back(top);
        s.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer;
}