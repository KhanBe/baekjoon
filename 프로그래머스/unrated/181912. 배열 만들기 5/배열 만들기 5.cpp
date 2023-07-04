#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    
    for (auto str : intStrs) {
        string temp(str.begin() + s, str.begin() + s + l);
        if (k < stoi(temp)) answer.push_back(stoi(temp));
    }
    return answer;
}