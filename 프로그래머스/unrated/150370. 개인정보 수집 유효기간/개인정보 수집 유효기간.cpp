#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int get_int_day(string today) {
    int int_today = 0;
    
    int_today += today[2] * 10 * 12 * 28;
    int_today += today[3] * 12 * 28;
    int_today += today[5] * 10 * 28;
    int_today += today[6] * 28;
    int_today += today[8] * 10;
    int_today += today[9];
    
    return int_today;    
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> map_terms;
    
    int int_today = get_int_day(today);
    
    //terms > map
    for (int i = 0; i < terms.size(); i++) {
        char alpha = terms[i][0];
        terms[i].erase(terms[i].begin(), terms[i].begin() + 2);

        map_terms.insert({alpha, stoi(terms[i])});
    }
    
    for (int i = 0; i < privacies.size(); i++) {
        char alpha = privacies[i][11];
        privacies[i].erase(10, 2);
        
        int int_expire = get_int_day(privacies[i]) + map_terms[alpha] * 28;
        
        if (int_today >= int_expire) answer.push_back(i + 1);
    }
    
    return answer;
}