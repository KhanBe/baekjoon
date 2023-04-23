#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    
    for (int i = 0; i < myString.length(); i++) {
        if ('A' <= myString[i]  && myString[i] <= 'Z') myString[i] += 32;
    }
    for (int i = 0; i < pat.length(); i++) {
        if ('A' <= pat[i] && pat[i] <= 'Z') pat[i] += 32;
    }

    return (myString.find(pat) != string::npos) ? 1 : 0;
}