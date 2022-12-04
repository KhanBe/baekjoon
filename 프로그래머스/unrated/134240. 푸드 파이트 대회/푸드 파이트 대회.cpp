#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    for (int i = 1; i < food.size(); i++) {
        int repeat = food[i] / 2;
        for (int j = 0; j < repeat; j++) {
            answer += '0' + i;
        }
    }
    string rev = answer;
    reverse(rev.begin(), rev.end());
    
    answer += '0' + rev;
    return answer;
}