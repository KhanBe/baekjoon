#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    if (participant.size() == 1) return participant[0];
    
    for (int i = 0; i < participant.size(); i++) {
        //if (i > completion.size()) continue;
        if (participant[i] != completion[i]) {
            answer = participant[i];
            break;
        }
    }
    
    return answer;
}