#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    
    int div = 2;
    while (n != 1) {
        if (n % div == 0) {
            //contains
            if (find(answer.begin(), answer.end(), div) == answer.end()) answer.push_back(div);
            n /= div;
            div = 1;
        }
        div++;
    }
    return answer;
}