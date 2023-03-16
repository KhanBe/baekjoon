#include <string>
#include <vector>

using namespace std;

vector<int> visited(50);
string target_word = "";
int answer = 50;

bool isOneDiff (string s1, string s2) {
    int diff = 0;
    
    for (int i = 0; i < s1.length(); i++) if (s1[i] != s2[i]) diff++;

    return diff == 1 ? true : false;
}


void dfs(string begin, vector<string> words, int step) {
    if (answer <= step) return ;
    
    if (begin == target_word) {
        answer = answer > step ? step : answer;
    }
    
    for (int i = 0; i < words.size(); i++) {
        if (isOneDiff(begin, words[i]) && !visited[i]) {
            visited[i] = true;
            dfs(words[i], words, step + 1);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    target_word = target;
        
    bool exist = false;
    for (auto w : words) if (target == w) exist = true;
    if (!exist) return 0;
    
    dfs(begin, words, 0);
    return answer;
}