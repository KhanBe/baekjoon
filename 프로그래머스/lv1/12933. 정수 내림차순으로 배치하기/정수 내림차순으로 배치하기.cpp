#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(char c1, char c2) {
    return c1 > c2;
}

long long atoll(char c) {
    return c - '0';
}

long long solution(long long n) {
    long long answer = 0;
    
    string s = "";
    while (n > 0) {
        char temp = '0' + (n % 10);
        
        s += temp;
        n /= 10;
    }
    
    sort(s.begin(), s.end(), compare);
    
    for (int i = 0; i < s.length(); i++) {
        answer += atoll(s[i]);
        if (i == s.length() - 1) break;
        answer *= 10;
    }

    return answer;
}