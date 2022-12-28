#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int price) {
    int answer = price;
    
    double temp = price;

    if (temp >= 500000){
        return floor(temp / 20 * 16);
    }
    else if (temp >= 300000){
        return floor(temp / 20 * 18);
    }
    else if (temp >= 100000){
        return floor(temp / 20 * 19);
    }
    return answer;
}