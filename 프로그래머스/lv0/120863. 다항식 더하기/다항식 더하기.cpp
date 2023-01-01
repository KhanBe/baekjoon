#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string polynomial) {
    string answer = "";
    int x_value = 0;
    int value = 0;
    
    for (int i = 0; i < polynomial.length(); i++) {
        int j = i;
        int temp = 0;
        if (polynomial[j] == 'x') {
            x_value++;
            j++;
            continue;
        }
        
        while ('0' <= polynomial[j] && polynomial[j] <= '9') {
            temp += polynomial[j] - '0';
            
            if (!('0' <= polynomial[j + 1] && polynomial[j + 1] <= '9')) {
                if (polynomial[j + 1] == 'x') {
                    x_value += temp;
                }
                else {
                    value += temp;
                }
                
                i += 2;
                break;
            }
            temp *= 10;
            j++;
        }
    }
    
    if (x_value != 0) {
        if (x_value == 1) answer += 'x';
        else answer += to_string(x_value) + 'x';
        if (value != 0) answer += " + " + to_string(value);
    }
    else {//x가 0일경우
        if (value != 0) answer += to_string(value);
    }
    return answer;
}