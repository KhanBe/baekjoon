#include <string>
#include <vector>

using namespace std;

string solution(string cipher, int code) {
    string answer = "";
    
    int cycle = 1;
    for (int i = 0; i < cipher.length(); i++) {
        
        if (cycle == code) {
            answer += cipher[i];
            cycle = 0;
        }
        cycle++;
    }
    return answer;
}