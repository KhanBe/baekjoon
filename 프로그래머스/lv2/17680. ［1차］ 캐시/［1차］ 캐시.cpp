#include <string>
#include <vector>
#include <list>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    list<string> l;
    
    for (int i = 0; i < cities.size(); i++) {
        for (int j = 0; j < cities[i].length(); j++) {
            cities[i][j] = tolower(cities[i][j]);   
        }
    }
    
    for (auto city : cities) {
        bool getMemory = false;
        
        for (auto iter = l.begin(); iter != l.end(); iter++) {
            if (*iter == city) {
                getMemory = true;
                l.erase(iter);
                break;
            }
        }
        l.push_back(city);
        
        if (l.size() > cacheSize) l.pop_front();
        
        if (getMemory) answer += 1;
        else answer += 5;
    }
    return answer;
}