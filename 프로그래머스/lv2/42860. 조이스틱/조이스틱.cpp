#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    int shift = name.length() - 1;
    
    for (int i = 0; i < name.length(); i++) {
        int count = name[i] - 'A';
        
        if (name[i] > 'N') count = 26 - count;
        answer += count;
        
        int index = i + 1;
        while(index < name.length() && name[index] == 'A') {//A가 아닌 index구하기
            index++;
        }
        
        
        int a = i;
        int b = name.length() - index;
        shift  = min(shift, min(2 * a + b, a + 2 * b));
        
    }

    answer += shift;
    return answer;
}