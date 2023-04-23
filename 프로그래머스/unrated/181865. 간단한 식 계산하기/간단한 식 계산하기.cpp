#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

int solution(string binomial) {
    int answer = 0;
    
    string a = "";
    string b = "";
    string op = "";
    for (int i = 0; i < binomial.length(); i++) {
        if (binomial[i] == ' ') {
            a = binomial.substr(0, i);
            b = binomial.substr(i + 3, binomial.length() - 1);
            op = binomial.substr(i + 1, 1);
            break;
        }
    }
    cout << a << " " << b << " " << op;
    
    if (op == "+") {
        answer = stoi(a) + stoi(b);
    }
    else if (op == "-") {
        answer = stoi(a) - stoi(b);
    }
    else {
        answer = stoi(a) * stoi(b);
    }
    return answer;
}