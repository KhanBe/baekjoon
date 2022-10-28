#include <string>
#include <vector>
#include <list>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    vector<int> answer;
    list<int> list;
    
    for (auto num : numbers) list.push_back(num);
    
    if (direction == "right") {
        int temp = list.back();
        list.pop_back();
        list.push_front(temp);
    }
    else {
        int temp = list.front();
        list.pop_front();
        list.push_back(temp);
    }
    
    for (auto l : list) answer.push_back(l);
    return answer;
}