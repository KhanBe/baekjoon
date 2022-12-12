#include <string>
#include <vector>
#include <sstream>

using namespace std;

//int to string method
string itos(int n) {
    string answer = "";
    int temp = n;
    
    if (temp < 0) temp *= -1;
    
    while (temp > 0) {
        char c = '0' + (temp % 10);
        answer = c + answer;
        temp /= 10;
    }
    
    if (n < 0) answer = '-' + answer;
    
    return answer;
}

string solution(string s) {
    string answer = "";
    int max = -2147483648;
    int min = 2147483647;
    
    stringstream ss;
    ss.str(s);
    
    int n = 0;
    while (ss >> n) {
        if (max < n) max = n;
        if (min > n) min = n;
    }
    
    answer += itos(min) + " " + itos(max);
    return answer;
}