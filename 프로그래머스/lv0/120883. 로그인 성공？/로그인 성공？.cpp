#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "";
    
    for (auto d : db) {
        if (id_pw[0] == d[0] && id_pw[1] == d[1]) {
            answer = "login";
            break;
        }
        else if (id_pw[0] == d[0] && id_pw[1] != d[1]) {
            answer = "wrong pw";
            break;
        }
    }
    if (answer == "") answer = "fail";
    return answer;
}