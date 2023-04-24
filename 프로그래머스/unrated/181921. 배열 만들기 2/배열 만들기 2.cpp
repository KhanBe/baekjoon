#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    
    for (int i = l; i <= r; i++) {
        if (i % 5 == 0) {
            bool correct = true;
            string s = to_string(i);
            for (auto word : s) {
                if (!(word == '0' || word == '5')) {
                    correct = false;
                    break;
                }
            }
            if (correct) answer.push_back(i);
        }
    }
    if (!answer.size()) answer.push_back(-1);
    return answer;
}