#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    map<string, int> map_want;
    //map_want 초기화
    for (int i = 0; i < want.size(); i++) {
        map_want.insert({want[i], number[i]});
    }
    
    //기본 세팅 map
    map<string, int> check_map(map_want);
    
    for (int i = 0; i < discount.size() - 9; i++) {
        for (int j = i; j < i + 10; j++) {
            if (map_want.find(discount[j]) != map_want.end()) {
                map_want[discount[j]] -= 1;
            }
        }
        
        //출력
        //for (auto iter : map_want) cout << iter.first << " : " << iter.second << "\n";
        //cout << "\n";
        
        //전체세일인지 아닌지 확인
        bool allSale = true;
        for (auto mw : map_want) {
            if (mw.second > 0) {
                allSale = false;
                break;
            }
        }
        if (allSale) answer++;
        
        //초기화
        map_want = check_map;
    }

    return answer;
}