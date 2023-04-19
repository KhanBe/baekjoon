#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> m;
    
    for (int i = 0; i < name.size(); i++) {
        m.insert({name[i], yearning[i]});
    }
    
    for (auto p : photo) {
        int memory = 0;
        for (auto human : p) {
            if (m.find(human) != m.end()) {
                memory += m[human];
            }
        }
        answer.push_back(memory);
    }
    return answer;
}