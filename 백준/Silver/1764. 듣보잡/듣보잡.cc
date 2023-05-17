#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	set<string> a;
	set<string> c;
	string buf;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> buf;
		a.insert(buf);
	}
	
	for (int i = 0; i < m; i++) {
		cin >> buf;
		if (a.find(buf) != a.end()) {
			c.insert(buf);
		}
	}

	cout << c.size() << '\n';
	for (set<string>::iterator it = c.begin(); it != c.end(); it++) {
		cout << *it << '\n';
	}
}