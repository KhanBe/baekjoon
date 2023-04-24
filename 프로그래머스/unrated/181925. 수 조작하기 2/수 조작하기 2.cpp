#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numLog) {
    string answer = "";
    int start = numLog[0];
    
    for (int i = 1; i < numLog.size(); i++) {
        int value = numLog[i] - start;
        
        if (value == 1) answer += 'w';
        else if (value == -1) answer += 's';
        else if (value == 10) answer += 'd';
        else answer += 'a';
        
        start = numLog[i];
    }
    return answer;
}