#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    priority_queue<int> pq;
    priority_queue<int> pq_temp;
    
    for (auto oper : operations) {
        if (oper == "D 1") {
            if (!pq.empty()) pq.pop();
        }
        else if(oper == "D -1") {
            while (pq.size() > 1) {
                pq_temp.push(pq.top());
                pq.pop();
            }
            if (!pq.empty()) pq.pop();
            while (!pq_temp.empty()) {
                pq.push(pq_temp.top());
                pq_temp.pop();
            }
        }
        else {
            oper.erase(0, 2);
            pq.push(stoi(oper));
        }
    }
    
    if (!pq.empty()) {
        answer[0] = pq.top();
        while (pq.size() > 1) {
            pq_temp.push(pq.top());
            pq.pop();
        }
        answer[1] = pq.top();
    }
    return answer;
}