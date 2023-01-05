#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> alphavet(257);
    
    for (int i = 0; i < s.length(); i++) {
        if (alphavet[s[i]] == 0) answer.push_back(-1);
        else answer.push_back(i - alphavet[s[i]] + 1);
        
        alphavet[s[i]] = i + 1;
    }
    return answer;
}