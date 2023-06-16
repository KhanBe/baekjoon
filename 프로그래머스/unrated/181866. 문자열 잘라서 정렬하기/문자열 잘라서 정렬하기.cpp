#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

vector<string> solution(string myString) {
    vector<string> answer;

    for (int i = 0; i < myString.length(); i++) {
        if (myString[i] == 'x') myString[i] = ' ';
    }
    
    stringstream ss(myString);
    
    string s;
    while (ss >> s) {
        answer.push_back(s);
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}