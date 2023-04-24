#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int start = -1, end = -1;
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 2) { start = i; break; }
    }
    if (start != -1) {//찾으면
        for (int i = start + 1; i < arr.size(); i++) {
            if (arr[i] == 2) end = i;
        }
    }
    else { answer.push_back(-1); return answer; }
    
    if (start != -1) {
        if (end != -1) {
            for (int i = start; i <= end; i++) {
                answer.push_back(arr[i]);
            }
        }
        else answer.push_back(2);
    }
    return answer;
}