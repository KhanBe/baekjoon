#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int left = 50;
    int right = 0;
    int top = 50;
    int bottom = 0;
    
    for (int i = 0; i < wallpaper.size(); i++) {
        for (int j = 0; j < wallpaper[i].length(); j++) {
            if (wallpaper[i][j] == '#') {
                left = j < left ? j : left;
                right = j > right ? j : right;
                top = i < top ? i : top;
                bottom = i > bottom ? i : bottom;
            }
        }
    }
    
    answer.push_back(top);
    answer.push_back(left);
    answer.push_back(bottom + 1);
    answer.push_back(right + 1);
    return answer;
}