#include <string>
#include <vector>

using namespace std;

string solution(string myString) {

    for (int i = 0; i < myString.length(); i++) {
        if ('a' <= myString[i] && myString[i] <= 'z') myString[i] -= 32;
    }
    return myString;
}