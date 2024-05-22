#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {

	sort(phone_book.begin(), phone_book.end());

	for (int i = 0; i < phone_book.size() - 1; i++) {
		string pivot = phone_book[i];
		string target = phone_book[i + 1];
		
		if (pivot == target.substr(0, pivot.size())) return false;
	}

    return true;
}