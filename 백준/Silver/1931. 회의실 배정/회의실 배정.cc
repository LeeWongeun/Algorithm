#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct lecture {
	int start = 0;
	int end = 0;
};

bool compare(lecture a, lecture b) {
	if (a.end == b.end) {
		return a.start < b.start;
	}
	return a.end < b.end;
}
int main() {
	vector<lecture> arr;
	int n, cnt = 0 , last = 0;
	lecture lec;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> lec.start >> lec.end;
		arr.push_back(lec);
	}

	sort(arr.begin(), arr.end(), compare);

	last = arr[0].end;
	cnt++;
	for (int i = 1; i < n; i++) {
		if (arr[i].start >= last) {
			cnt++;
			last = arr[i].end;
		}
	}
	cout << cnt;
}