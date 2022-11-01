#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> memo(256);
    
    for (auto a : s) memo[(int)a]++;

    for (int i = 0; i < memo.size(); i++) {
        if (memo[i] == 1) answer += i;
    }
    return answer;
}