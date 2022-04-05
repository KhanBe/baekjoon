#include <iostream>
#include <stack>
#include <array>

using namespace std;

int main(void)
{
    int n;

    stack<int> st;
    array<int, 1000000> answer = {0};
    array<int, 1000000> nums = {0};

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i])
            st.pop();

        if (st.empty())
            answer[i] = -1;
        else
            answer[i] = st.top();

        st.push(nums[i]);
    }

    for(int i =0;i<n;i++)
        cout << answer[i] << " ";
}