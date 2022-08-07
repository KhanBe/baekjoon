#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_width = 0;
    int max_height = 0;

    for (int i=0;i < sizes.size();i++){
        for (int j=0;j<2;j++){
            
            if (sizes[i][0] < sizes[i][1]) {//swap
                int temp = 0;
                temp = sizes[i][1];
                sizes[i][1] = sizes[i][0];
                sizes[i][0] = temp;
            }
            
            if (max_width < sizes[i][0]) max_width = sizes[i][0];
            if (max_height < sizes[i][1]) max_height = sizes[i][1];
        }
    }
    
    return max_width * max_height;
}