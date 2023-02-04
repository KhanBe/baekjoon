#include <string>
#include <vector>
#include <iostream>
#include <array>

using namespace std;

//97~122 소문자
string solution(string s, string skip, int index) {
    array<int, 26> alpha = {0,};
    
    for (auto sk : skip) alpha[sk - 'a']++;
    
    //for (auto a : alpha) cout << a << " ";
    //cout << "\n";
    
    for (int i = 0; i < s.length(); i++) {
        int j = 0;
        int count = index;
        
        while (count != 0) {
            if (s[i] - 'a' + j + 1 > 25) j -= 26;
            
            if (alpha[s[i] - 'a' + j + 1] == 0) count--;
            j++;
        }
        
        s[i] += j;
    }
    return s;
}