#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    for (int i = 0; i < myString.length(); i++) {
        if ('A' <= myString[i] && myString[i] <= 'Z') myString[i] += 32;
    }
    return myString;
}