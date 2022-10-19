#include <string>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string solution(string my_string, string letter) 
{
    for (auto l : letter)
        my_string.erase(remove(my_string.begin(), my_string.end(), l), my_string.end());

    return my_string;
}