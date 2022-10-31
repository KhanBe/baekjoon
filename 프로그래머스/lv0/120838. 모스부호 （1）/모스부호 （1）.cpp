#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

string solution(string letter) {
    string answer = "";
    string str = "";
    stringstream ss(letter);
    
    vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",
				".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
                "...","-","..-","...-",".--","-..-","-.--","--.."};
    map<string, char> mp;
    
    for (int i = 0; i < 26; i++) {
        mp[morse[i]] = 'a' + i;
    }
    while (ss >> str) {
        answer += mp[str];
    }
    return answer;
}