#include <numeric>
#include<iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	cout << gcd(m, n) << "\n" << lcm(m, n);
}