#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(string numbers) {
    long long answer = 0;
    
    while (numbers.find("zero") != string::npos)
        numbers.replace(numbers.find("zero"), 4, "0");
    
    while (numbers.find("one") != string::npos)
        numbers.replace(numbers.find("one"), 3, "1");
    
    while (numbers.find("two") != string::npos)
        numbers.replace(numbers.find("two"), 3, "2");
    
    while (numbers.find("three") != string::npos)
        numbers.replace(numbers.find("three"), 5, "3");
    
    while (numbers.find("four") != string::npos)
        numbers.replace(numbers.find("four"), 4, "4");
    
    while (numbers.find("five") != string::npos)
        numbers.replace(numbers.find("five"), 4, "5");
    
    while (numbers.find("six") != string::npos)
        numbers.replace(numbers.find("six"), 3, "6");
    
    while (numbers.find("seven") != string::npos)
        numbers.replace(numbers.find("seven"), 5, "7");
    
    while (numbers.find("eight") != string::npos)
        numbers.replace(numbers.find("eight"), 5, "8");
    
    while (numbers.find("nine") != string::npos)
        numbers.replace(numbers.find("nine"), 4, "9");
    
    answer = stoll(numbers);
    return answer;
}