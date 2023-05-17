#include <iostream>

using namespace std;

void push(int a);
int pop();
int size();
int empty();
int top();

int stack[10000];
int t = -1;

int main() {
	int n, a;
	string command;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> command;

		if (command.compare("push")==0) {
			cin >> a;
			push(a);
		}
		else if (command.compare("pop") == 0) {
			cout << pop() << '\n';
		}
		else if (command.compare("size") == 0) {
			cout << size() << '\n';
		}
		else if (command.compare("empty") == 0) {
			cout << empty() << '\n';
		}
		else if (command.compare("top") == 0) {
			cout << top() << '\n';
		}
	}
}

void push(int a) {
	t++;
	stack[t] = a;
}

int pop() {
	if (t == -1) {
		return -1;
	}
	else {
		return stack[t--];
	}
}

int size() {
	return t + 1;
}

int empty() {
	if (t == -1) 
		return 1;

	else
		return 0;
}

int top() {
	if (t == -1) {
		return -1;
	}
	return stack[t];
}