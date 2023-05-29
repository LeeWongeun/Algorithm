#include <iostream>
#include <algorithm>

using namespace std;

int arrN[500000];

int BS(int arr[], int a, int end) {
	int begin = 0;
	int mid = end / 2;

	while (begin <= end) {
		mid = (begin + end) / 2;
		if (arr[mid] == a) {
			return mid;
		}
		else if (arr[mid] > a) {
			end = mid - 1;
		}
		else {
			begin = mid + 1;
		}
	}
	return -1;
}

int BS_count(int arr[], int a, int end) {
	int begin = 0;
	int endOrg = end;
	int mid = end / 2;

	int cntStart = 0, cntEnd = 0;

	while (begin <= end) {
		mid = (begin + end) / 2;
		if (arr[mid] > a) {
			end = mid - 1;
		}
		else {
			begin = mid + 1;
		}
	}
	cntEnd = end;
	end = endOrg;
	begin = 0;
	while (begin <= end) {
		mid = (begin + end) / 2;
		if (arr[mid] < a) {
			begin = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	cntStart = begin;
	return (cntEnd - cntStart + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, M, size=-1, cnt=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arrN[i];
		size++;
	}
	sort(arrN, arrN + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> M;
		cnt = BS_count(arrN, M, size);
		cout << cnt << ' ';
	}
}