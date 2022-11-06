#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    stringstream ss(s);
    
    string parse_str = "";
    vector<string> prev_strs;
    
    while (ss >> parse_str) {
        if (parse_str == "Z") {
            if (!prev_strs.empty()) {
                answer -= stoi(prev_strs.back());
                prev_strs.pop_back();   
            }            
        }
        else {
            answer += stoi(parse_str);
            prev_strs.push_back(parse_str);
        }
    }
    return answer;
}