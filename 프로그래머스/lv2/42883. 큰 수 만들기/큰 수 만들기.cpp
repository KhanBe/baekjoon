#include <string>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    stack<char> s;
    
    int i = 0;
    for (int j=0;j<number.length();j++) {
        while (!s.empty() && s.top() < number[i]){
            s.pop();
            k--;
            if (k == 0) {
                while (i <= number.length() - 1) {
                    s.push(number[i]);
                    i++;
                }
            }
        }
        if (k == 0) break;
        
        s.push(number[i]);
        i++;
    }
    
    while (k--) s.pop();//"4321" 같은 경우도 있기 때문에
    
    while (!s.empty()) {//join
        answer = s.top() + answer;
        s.pop();
    }
    return answer;
}