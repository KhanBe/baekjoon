#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    int first = (total / num) - (num / 2);
    
    if (num % 2 == 0) first++;
    
    for (int i = first; i < first + num; i++) answer.push_back(i);
    return answer;
}