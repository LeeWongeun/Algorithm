#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct coordinate {
	int x = 0;
	int y = 0;
};

bool compare(coordinate a, coordinate b) {
	if (a.x < b.x) {
		return a.x < b.x;
	}
	else if (a.x == b.x) {
		return a.y < b.y;
	}
	else {
		return false;
	}
}
int main() {
	vector<coordinate> v;
	coordinate buf;
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> buf.x >> buf.y;
		v.push_back(buf);
	}
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << v[i].x << ' ' << v[i].y << '\n';
	}
}