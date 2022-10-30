#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    vector<int> ascii(256);
    
    for (int i = 0; i < my_string.length(); i++) {
        if (ascii[(int)my_string[i]] == 0) {
            ascii[(int)my_string[i]]++;
            answer += my_string[i];
        }
    }
    return answer;
}