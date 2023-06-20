#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    // myString.begin() + 
    for (int i = 0; i < myString.length() - pat.length() + 1; i++) {
        string temp(myString.begin() + i, myString.begin() + (i + pat.length()));
        if (pat == temp) answer++;
    }
    return answer;
}