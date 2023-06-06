#include <string>
#include <vector>

using namespace std;

vector<string> solution(string myStr) {
    vector<string> answer;
    
    for (int i = 0; i < myStr.length(); i++) {
        if ('a' <= myStr[i] && myStr[i] <= 'c'){
            myStr[i] = ' ';
        }
    }
    
    string temp = "";
    for (int i = 0; i < myStr.length(); i++) {
        if (myStr[i] == ' ') {
            if (temp != "") {
                answer.push_back(temp);
                temp = "";
            }
            continue;
        }
        else {
            temp += myStr[i];
        }
    }
    
    if (temp != "") answer.push_back(temp);
    
    if (answer.size() == 0) answer.push_back("EMPTY");
    return answer;
}