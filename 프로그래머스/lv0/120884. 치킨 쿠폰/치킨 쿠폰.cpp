#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int chicken) {
    //주문 치킨
    int answer = 0;
    
    int coupon = 0;
    while (chicken >= 10) {
        int service = chicken / 10;
        int coupon = chicken % 10;
        
        chicken = service + coupon;
        answer += (chicken - coupon);
    }
    return answer;
}