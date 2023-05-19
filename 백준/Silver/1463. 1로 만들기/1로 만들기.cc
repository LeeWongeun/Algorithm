#include <iostream>

using namespace std;

int a[1000001] = {0,0,1,1};

int func(int N) {
	int x;
	if (N == 1 || N == 0) return 0;
	else if (a[N] != 0) return a[N];
	else if (N > 3) {
		x = 1 + func(N - 1);
		if (N % 3 == 0) x = min(x, a[N / 3] + 1);
		if (N % 2 == 0) x = min(x, a[N / 2] + 1);
		a[N] = x;
		return x;
	}
}
int main() {
	int N = 0;
	cin >> N;
	cout << func(N);
}