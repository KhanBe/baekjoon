#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> dp(triangle);
    //0초기화
    for (int i = 0; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = triangle[0][0];

    for (int i = 0; i < triangle.size() - 1; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (dp[i + 1][j] < dp[i][j] + triangle[i + 1][j])
                dp[i + 1][j] = dp[i][j] + triangle[i + 1][j];
            if (dp[i + 1][j + 1] < dp[i][j] + triangle[i + 1][j + 1])
                dp[i + 1][j + 1] = dp[i][j] + triangle[i + 1][j + 1];
        }
    }

    //최대값 산출
    for (int i = 0; i < dp[dp.size() - 1].size(); i++) {
        if (answer < dp[dp.size() - 1][i]) answer = dp[dp.size() - 1][i];
    }
    return answer;
}