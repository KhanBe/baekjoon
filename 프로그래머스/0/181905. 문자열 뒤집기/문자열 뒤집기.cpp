#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int s, int e) {  
    int l = (e - s + 1) / 2;
    
    for (int i = 0; i < l; i++) {
        char temp = my_string[s + i];
        my_string[s + i] = my_string[e - i];
        my_string[e - i] = temp;
    }
    return my_string;
}