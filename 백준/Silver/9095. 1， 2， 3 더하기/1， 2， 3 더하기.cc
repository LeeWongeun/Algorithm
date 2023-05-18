#include <iostream>

using namespace std;

int a[100] = { 0,1,2,4 };

int dp(int n) {
	if (a[n] != 0) return a[n];
	else if (n > 3) {
		a[n] = dp(n - 1) + dp(n - 2) + dp(n - 3);
		return a[n];
	}
}
int main() {
	int T, testcase[100];
	cin >> T;

	for (int i = 0; i < T; i++) cin >> testcase[i];

	for (int i = 0; i < T; i++) {
		cout << dp(testcase[i]) << '\n';
	}
}