#include <iostream>
using namespace std;

int a[1001] = { 0,1,2 };

int dp(int n) {

	if (a[n] != 0) return a[n];
	else if(n >= 3) {
		a[n] = (dp(n - 1) + dp(n - 2)) % 10007;
	}
	return a[n];
}
int main() {
	int n;

	cin >> n;
	dp(n);
	cout << a[n];
}