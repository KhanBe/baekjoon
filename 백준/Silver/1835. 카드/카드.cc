#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    list<int> card;

    int n;
    cin >> n;

    card.push_back(n);

    for (int i = n - 1; i > 0; i--)
    {
        card.push_front(i);
        for (int j = 0; j < i; j++)
        {
            card.push_front(card.back());
            card.pop_back();
        }
    }
    for (auto iter = card.begin(); iter != card.end(); iter++)
    {
        cout << *iter << " ";
    }
}