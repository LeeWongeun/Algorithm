#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct user {
	int year = 0;
	char name[101] = {};
	int no = 0;
};

bool compare(user a, user b) {
	if (a.year < b.year) {
		return a.year < b.year;
	}
	else if (a.year == b.year) {
		return a.no < b.no;
	}
	else {
		return false;
	}
}

int main() {
	int n;
	user buf;
	vector<user> u;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> buf.year >> buf.name;
		buf.no = i;
		u.push_back(buf);
	}

	sort(u.begin(), u.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << u[i].year << ' ' << u[i].name <<'\n';
	}
}