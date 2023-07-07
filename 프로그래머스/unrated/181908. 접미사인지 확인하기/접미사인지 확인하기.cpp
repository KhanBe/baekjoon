#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) {
    int answer = 0;
    
    for (int i = 0; i < my_string.length(); i++) {
        string temp(my_string.begin() + i, my_string.end());
        if (is_suffix == temp) {
            answer = 1;
            break;
        }
    }
    return answer;
}