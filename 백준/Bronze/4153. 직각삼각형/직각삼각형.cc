#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int A[3], M;
	int a, b, c, m;
	while (1) {
		M = 0;
		for (int i = 0; i <3; i++) {
			cin >> A[i];
			M = max(M, A[i]);
		}
		a = pow(A[0], 2);
		b = pow(A[1], 2);
		c = pow(A[2], 2);
		m = pow(M, 2);
		if (a == 0 && b == 0 && c == 0) {
			return 0;
		}
		if (m-(a+b+c) == -m) {
			cout << "right"<<'\n';
		}
		else {
			cout << "wrong"<<'\n';
		}
	}
}