#include <string>
#include <vector>

using namespace std;

//bin to int
int btoi(string bin) {
    int count = 1;
    int answer = 0;
    int temp = stoi(bin);
    
    while (temp > 0) {
        answer += (temp % 10) * count;
        
        count *= 2;
        temp /= 10;
    }
    
    return answer;
}

//int to bin
string itob(int num) {
    
    if (num == 0) return "0";
    
    string answer = "";
    int temp = num;
    
    while (temp > 0) {
        answer = (char)((temp % 2) + '0') + answer;
        
        temp /= 2;
    }
    
    return answer;
}

string solution(string bin1, string bin2) {
    return itob(btoi(bin1) + btoi(bin2));
}