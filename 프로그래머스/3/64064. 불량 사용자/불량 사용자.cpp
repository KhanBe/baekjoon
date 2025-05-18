#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

bool visited[9] = {};
vector<string> user_temp;
vector<string> banned_temp;
set<string> s;

bool strComp(string user, string ban) {
    //cout << user << " " << ban << "\n";
    
    if (user.length() != ban.length()) return false;
    
    for (int i =0; i < user.length(); i++) {
        if (ban[i] == '*') continue;
        if (user[i] == ban[i]) continue;
        else return false;
    }
    
    //cout << user << " " << ban << "검증성공\n";
    return true;    
}

void recur(int id) {
    if (banned_temp.size() <= id) {
        string temp = "";
        for (int i =0;i < user_temp.size(); i++) {
            if (visited[i]) {
                temp += i + '0'; // string 에 숫자추가
            }
        }
        s.insert(temp);
        return ;
    }
    
    for (int i = 0; i < user_temp.size(); i++) {
        if (visited[i]) continue;
        
        if (strComp(user_temp[i], banned_temp[id])) {
            visited[i] = true;
            recur(id + 1);
            visited[i] = false;
        }
    }
    
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    user_temp = user_id;
    banned_temp = banned_id;
    
    recur(0);
    
    return s.size();
}