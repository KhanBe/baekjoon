#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int getDivisorCount(int n) {
    int divisorCount = 0;
    
    for (int i = 1; i * i <= n; i++) {
        if (i * i == n) divisorCount++;
        else if (n % i == 0) divisorCount += 2;
    }
    
    return divisorCount;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for (int i = 1; i <= number; i++) {
        int weight = 0;
        if (limit < getDivisorCount(i)) weight = power;
        else weight = getDivisorCount(i); 
        
        cout << weight << "\n";
        answer += weight;
    }
    
    return answer;
}