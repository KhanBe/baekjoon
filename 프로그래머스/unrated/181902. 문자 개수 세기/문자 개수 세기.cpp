#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer(52);
    
    for (auto string : my_string) {
        if ('a' <= string && string <= 'z') {
            answer[26 + string - 'a']++;
        }
        else {
            answer[string - 'A']++;
        }
    }
    return answer;
}