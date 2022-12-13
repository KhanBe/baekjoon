#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
        int answer = 0;

        double A = a;
        double B = b;
    
        if (a > b){
            A = b;
            B = a;
        }
        
        int count = 0;
        
        while (true){
            if (A + 1 == B && (int)A % 2 == 1){
                count++;
                return count;
            }
            A = ceil(A / 2);
            B = ceil(B / 2);
            count++;
        }
    return answer;
}