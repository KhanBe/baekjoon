#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    
    int start = 0;
    for (int i = 0; i < my_string.length(); i++) {
        if (my_string[i] == ' ') {
            string s(my_string.begin() + start, my_string.begin() + i);
            answer.push_back(s);
            start = i + 1;
        }
    }
    
    string s(my_string.begin() + start, my_string.end());
    answer.push_back(s);
    return answer;
}