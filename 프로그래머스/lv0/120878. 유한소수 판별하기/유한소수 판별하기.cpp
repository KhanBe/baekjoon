#include <string>
#include <vector>
#include <iostream>

using namespace std;

int gcd(int a, int b) {
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int solution(int a, int b) {
    int answer = 1;
    int g = gcd(a, b);
    vector<int> s;

    a /= g;
    b /= g;
    
    for (int i = 2; i <= b; i++) {
        if (b % i == 0) {//소수 구하기
            int count = 0;
            
            for (int j = 1; j <= i; j++) {
                if (i % j == 0) count++;
            }
            if (count == 2) s.push_back(i);
        }
    }

    for (auto ss : s) {//2나 5가 아닐경우 
        if (ss != 2 && ss != 5) answer = 2;
    }
    return answer;
}