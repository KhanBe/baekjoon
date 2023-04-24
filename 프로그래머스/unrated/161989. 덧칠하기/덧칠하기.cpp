#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    queue<int> q;
    
    for (auto s : section) q.push(s);
    
    while (!q.empty()) {
        int point = q.front() + m - 1;
        while (!q.empty() && q.front() <= point) {
            q.pop();
        }
        answer++;
    }
    return answer;
}