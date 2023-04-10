#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quick_Sort(vector<int> &A, int S, int E, int K);
void swap(vector<int> &A, int S, int E);
int partition(vector<int> &A, int S, int E);

void quick_Sort(vector<int> &A, int S, int E, int K) {
	int pivot = partition(A, S, E);

	if (pivot == K) return;
	else if (K < pivot) {//왼쪽만 보면됨
		quick_Sort(A, S, pivot - 1, K);
	}
	else if (pivot < K) {
		quick_Sort(A, pivot + 1, E, K);
	}
}

int partition(vector<int> &A, int S, int E) {
	//S = 파티션의 첫인덱스, E = 파티션의 마지막인덱스
	if (S + 1 == E) {
		if (A[S] > A[E]) swap(A, S, E);
		return E;
	}

	//가운데를 피봇으로
	int M = (S + E) / 2;
	//피봇을 맨 앞으로
	swap(A, S, M);
	
	int pivot = A[S];
	int i = S + 1;
	int j = E;

	while (i <= j) {//A[i] = start, A[j] = end 
		while (pivot < A[j] && 0 < j) j--;
		while (pivot > A[i] && i < A.size() - 1) i++;

		if (i <= j) swap(A, i++, j--);
	}
	//피봇데이터를 중간으로 스왑
	A[S] = A[j];
	A[j] = pivot;

	return j;
}

void swap(vector<int> &A, int S, int E) {
	int temp = A[S];
	A[S] = A[E];
	A[E] = temp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	cin >> N >> K;
	vector<int> A(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	quick_Sort(A, 0, N - 1, K - 1);
	cout << A[K - 1];
}