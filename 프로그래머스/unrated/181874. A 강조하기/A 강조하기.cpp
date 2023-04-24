#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    
    for (int i = 0; i < myString.length(); i++) {
        if (myString[i] == 'a') {
            myString[i] -= 32;
            continue;
        }
        if ('B' <= myString[i] && myString[i] <= 'Z') myString[i] += 32;
    }
    return myString;
}