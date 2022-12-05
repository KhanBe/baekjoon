#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(char c1, char c2) {
    return c1 > c2;
}

string solution(string X, string Y) {
    string answer = "";
    
    vector<int> arrX(10);
    vector<int> arrY(10);
    
    for (int i = 0; i < X.length(); i++) arrX[X[i] - '0']++;
    
    for (int i = 0; i < Y.length(); i++) arrY[Y[i] - '0']++;
    
    for (int i = 9; i >= 0; i--) {
        int min = 3000000;
        if (arrX[i] < min) min = arrX[i];
        if (arrY[i] < min) min = arrY[i];
        
        for (int j = 0; j < min; j++) answer += '0' + i;
    }
    
    if (answer == "") return "-1";
    if (answer[0] == '0' && answer[1] == '0') return "0";
    return answer;
}