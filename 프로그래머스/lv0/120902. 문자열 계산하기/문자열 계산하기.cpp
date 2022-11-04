#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int len(int n) {
    int answer = 0;
    while (n > 0) {
        n /= 10;
        
        answer++;
    }
    return answer;
}

bool isPlusMinus(char c) {
    if (c == '+' || c == '-') return 1;
    return 0;
}

bool isDigit(char c) {
    if ('0' <= c && c <= '9') return 1;
    return 0;
}

int solution(string my_string) {
    int answer = stoi(my_string);
    int calNum = stoi(my_string);
    string plusMinus = "";
    
    my_string.erase(my_string.begin(), my_string.begin() + len(calNum));
    
    while (my_string.length() != 0) {
        if (isPlusMinus(my_string[0])) {
            plusMinus = my_string[0];
            my_string.erase(my_string.begin(), my_string.begin() + 2);
        }

        else if (isDigit(my_string[0])) { 
            calNum = stoi(my_string);
            
            if (plusMinus == "+") {
                answer += calNum;
            }
            else if (plusMinus == "-") {
                answer -= calNum;
            }
            
            my_string.erase(my_string.begin(), my_string.begin() + len(calNum));
        }
        //공백일 경우
        else my_string.erase(my_string.begin(), my_string.begin() + 1);
    }
    return answer;
}