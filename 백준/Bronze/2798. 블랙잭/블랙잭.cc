#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	int C[100], n, m;
	int ans = 0 , a, sum;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> C[i];
	}

	for (int i = 0; i < n-2; i++) {
		for (int j = i + 1; j < n-1; j++) {
			for (int k = j + 1; k < n; k++) {
				sum = C[i] + C[j] + C[k];
				a = abs(sum - m);
				if (abs(ans - m) > a && m>=sum) {
					ans = sum;
				}
			}
		}
	}
	cout << ans;
}