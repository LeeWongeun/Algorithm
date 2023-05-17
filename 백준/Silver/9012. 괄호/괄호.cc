#include <iostream>
#include <stack>

using namespace std;

bool isVPS(string str) {
	stack<char> s;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			s.push('(');
		}
		else {
			if (s.empty()) {
				return false;
			}
			s.pop();
		}
	}

	if (!s.empty()) 
		return false;
	
	else
		return true;
}
int main() {
	int n;
	string str;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;
		if (isVPS(str)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}