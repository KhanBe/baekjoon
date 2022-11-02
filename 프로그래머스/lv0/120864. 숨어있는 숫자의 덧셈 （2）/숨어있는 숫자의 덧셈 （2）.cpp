#include <string>
#include <vector>

using namespace std;

bool isNumber(char c) {
    if ('0' <= c && c <= '9') return true;
    return false;
}

int solution(string my_string) {
    int answer = 0;
    
    for (int i = 0; i < my_string.length(); i++) {
        int tempNum = 0;
        //자연수이면
        while (isNumber(my_string[i])) {
            tempNum *= 10;
            tempNum += my_string[i++] - '0';
        }
        answer += tempNum;
    }
    return answer;
}