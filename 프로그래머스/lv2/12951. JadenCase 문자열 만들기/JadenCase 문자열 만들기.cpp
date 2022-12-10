#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    bool first = true;
    for (int i = 0; i < s.length(); i++) {
        if ('A' <= s[i] && s[i] <= 'Z') s[i] = tolower(s[i]);
    }
    
    for (int i = 0; i < s.length(); i++) {
        if (first) {
            first = false;
            s[i] = toupper(s[i]);
        }
        if (s[i] == ' ') first = true;
    }
    return s;
}