#include<iostream>
#include<algorithm>

using namespace std;

int BinarySearch(int A[], int size, int d) {
	int begin = 0, end = size - 1;
	int index = size - 1;
	while (begin <= end) {
		if (A[(begin+end) / 2] > d) {
			end = ((begin + end) / 2) - 1;
		}
		else if (A[(begin + end) / 2] == d) {
			return (begin+end) / 2;
		}
		else if (A[(begin + end) / 2] < d) {
			begin = ((begin + end) / 2) + 1;
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A[100000], B[100000], n, m;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> B[i];
	}

	sort(A, A + n);

	for (int i = 0; i < m; i++) {
		if (BinarySearch(A,n,B[i]) == -1) {
			cout << "0" << "\n";
		}
		else {
			cout << "1" << "\n";
		}
	}
}