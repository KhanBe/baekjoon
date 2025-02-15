#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    int l = num_list.size();
    
    if (num_list[l-1] > num_list[l-2]) num_list.push_back(num_list[l-1] - num_list[l-2]);
    else num_list.push_back(num_list[l-1] * 2);
    
    return num_list;
}