#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    
    vector<int> month_day = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int days = 0;
    
    for (int i = 0;i < a - 1 ;i++) days += month_day[i];
    
    days += b;
    days %= 7;
    
    if (days == 1) answer = "FRI";
    else if (days == 2) answer = "SAT";
    else if (days == 3) answer = "SUN";
    else if (days == 4) answer = "MON";
    else if (days == 5) answer = "TUE";
    else if (days == 6) answer = "WED";
    else if (days == 0) answer = "THU";
    
    return answer;
}