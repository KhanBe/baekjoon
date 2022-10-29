#include <string>
#include <vector>
#include <numeric>

using namespace std;

vector<int> solution(int denum1, int num1, int denum2, int num2) {
    vector<int> answer(2);
    
    //분자
    int topNum = num1*denum2 + num2*denum1;
    // 분모
    int botNum = num1*num2;
    // 최소 공배수
    int maximum = 1;
    // 약분
    for (int i = 1 ; i <= topNum ; i ++) {
        if (topNum%i == 0 && botNum%i == 0) {
            maximum = i;
        }
    }
    answer[0] = topNum/maximum;
    answer[1] = botNum/maximum;
    return answer;
}