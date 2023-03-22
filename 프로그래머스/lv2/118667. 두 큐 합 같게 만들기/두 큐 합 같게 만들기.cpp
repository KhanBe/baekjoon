#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    int q_size = queue1.size();
    long long int index1 = 0, index2 = 0;
    long long int sum1 = 0, sum2 = 0;
    
    for (auto q1 : queue1) sum1 += q1;
    for (auto q2 : queue2) sum2 += q2;
    
    while (answer < (q_size << 2)) {//(q_size << 2) 곱4
        if (sum1 > sum2) {
            sum1 -= queue1[index1];
            sum2 += queue1[index1];
            queue2.push_back(queue1[index1++]);
        }
        else if (sum1 < sum2) {
            sum1 += queue2[index2];
            sum2 -= queue2[index2];
            queue1.push_back(queue2[index2++]);
        }
        else {
            return answer;
        }
        answer++;
    }
    return -1;
}