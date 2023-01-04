#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    int cal = 0;
    
    for (auto q : quiz) {
        bool plus = true;
        int i = 0;
        string temp = "";
        while (q[i] != ' ') {
            temp += q[i++];
        }

        cal = stoi(temp);
        i++;
        if (q[i] == '-') plus = false;
        i += 2;
        
        temp = "";
        while (q[i] != ' ') {
            temp += q[i++];
        }
        
        if (plus) cal += stoi(temp);
        else cal -= stoi(temp);
        i += 3;
        
        temp = "";
        while (i <= q.length() - 1) {
            temp += q[i++];
        }
        
        if (cal == stoi(temp)) answer.push_back("O");
        else answer.push_back("X");
    }
    return answer;
}