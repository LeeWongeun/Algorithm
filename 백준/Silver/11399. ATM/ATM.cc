#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N, sum = 0;
	int P[1001], a[1001] = { 0 };

	cin >> N;
	for (int i = 0; i < N; i++) cin >> P[i];

	sort(P, P + N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			a[i] += P[j];
		}
	}

	for (int i = 0; i < N; i++) {
		sum += a[i];
	}

	cout << sum;
}