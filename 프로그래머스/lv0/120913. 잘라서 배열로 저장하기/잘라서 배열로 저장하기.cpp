#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;

    int count = 1;
    int index = 0;
    
    //vector 크기 늘리기
    for (int i = 0; i < ceil((double)my_str.length() / n); i++) answer.push_back("");
    
    for (int i = 0; i < my_str.length(); i++) {
        answer[index] += my_str[i];
        
        if (count == n) {
            count = 0;
            index++;
        }
        count++;
    }
    return answer;
}