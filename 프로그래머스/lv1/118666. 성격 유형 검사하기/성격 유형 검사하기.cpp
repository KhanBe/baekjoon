#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    map<char, int> rt;
    
    rt.insert({'R', 0});
    rt.insert({'T', 0});
    rt.insert({'C', 0});
    rt.insert({'F', 0});
    rt.insert({'J', 0});
    rt.insert({'M', 0});
    rt.insert({'A', 0});
    rt.insert({'N', 0});
    
    for (int i = 0; i <survey.size(); i++) {
        if (choices[i] - 4 > 0) {
            rt[survey[i][1]] += abs(choices[i] - 4);
        }
        else if (choices[i] - 4 < 0) {
            rt[survey[i][0]] += abs(choices[i] - 4);
        }
    }
    
    if (rt['R'] >= rt['T']) answer += 'R';
    else answer += 'T';
    if (rt['C'] >= rt['F']) answer += 'C';
    else answer += 'F';
    if (rt['J'] >= rt['M']) answer += 'J';
    else answer += 'M';
    if (rt['A'] >= rt['N']) answer += 'A';
    else answer += 'N';
    return answer;
}