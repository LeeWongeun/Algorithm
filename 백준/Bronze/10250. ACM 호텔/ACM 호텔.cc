#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int t, h, w, n;
	float a;
	int b;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> h >> w >> n;
		a = (float)n / (float)h;
		a = ceil(a);

		b = n % h;
		if (b == 0) b = h;

		cout << (b * 100) + a << '\n';
	}
}