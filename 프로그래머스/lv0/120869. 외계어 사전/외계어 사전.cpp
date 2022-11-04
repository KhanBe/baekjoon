#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    vector<string> spell_temp = spell;
    vector<int> spell_catch;
 
    for (int i = 0; i < spell.size(); i++) spell_catch.push_back(false);
    
    for (auto d : dic) {
        bool answer = true;
        
        for (int i = 0; i < d.length(); i++) {
            string s;
            s = d[i];
            
            //있으면
            size_t pos;
            if (find(spell.begin(), spell.end(), s) != spell.end()) {
                pos = find(spell.begin(), spell.end(), s) - spell.begin();//찾은 인덱스
                spell_catch[pos]++;
            }
        }
        for (auto sc : spell_catch) {
            if (sc < 1) {
                answer = false;
                break;
            }
        }
        if (answer) return 1;
        
        for (int i = 0; i < spell_catch.size(); i++) spell_catch[i] = 0;
    }
    return 2;
}