#include <string>
#include <vector>
#include <iostream>

using namespace std;

string toBinary(int n, int length) {
    string answer = "";
    
    int temp = 1;

    while (length != 0) {
        string s;
        s = '0' + (n % 2);
        answer = s + answer;
        n /= 2;
        
        length--;
    }
    return answer;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
       
    for (int i = 0; i < arr1.size(); i++) {
        answer.push_back(toBinary(arr1[i] | arr2[i], n));
    }
    
    //숫자 > 문자 변환
    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer[i].size(); j++) {
            if (answer[i][j] == '1') answer[i][j] = '#';
            else answer[i][j] = ' ';
        }
    }
    return answer;
}