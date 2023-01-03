#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int x = 1;
    
    char first = s[0];
    
    int i = 0;
    for (i = 1; i < s.length(); i++) {
        if (first == s[i]) x++;
        else x--;
        
        if (x == 0) {
            answer++;
            x = 1;
            first = s[i + 1];
            i++;
        }
    }
    
    if (i == s.length()) answer++;
    return answer;
}