#include <iostream>

void push(int a);
void pop();
void size();
void empty();
void front();
void back();

using namespace std;

int q[20000];
int f = 0, r = 0;
int maxSize = 20000, qSize=0;

int main() {
	int N, num;
	string cmd;
	cin >> N;
	for (int i=0; i < N; i++) {
		cin >> cmd;
		if (!cmd.compare("push")) {
			cin >> num;
			push(num);
		}
		else if (!cmd.compare("pop")) {
			pop();
		}
		else if (!cmd.compare("size")) {
			size();
		}
		else if (!cmd.compare("empty")) {
			empty();
		}
		else if (!cmd.compare("front")) {
			front();
		}
		else if (!cmd.compare("back")) {
			back();
		}
	}
}

void push(int a) {
	if (f == (r+1) % maxSize) {
		cout << "queue is Full\n";
		return;
	}
	r = ++r % maxSize;
	q[r] = a;
	qSize++;
}

void pop() {
	if (f==r) {
		cout << -1 <<'\n';
		return;
	}
	f = ++f % maxSize;
	cout << q[f] << "\n";
	qSize--;
}

void size() {
	cout << qSize << "\n";
}

void empty() {
	if (qSize == 0) {
		cout << 1 << "\n";
	}
	else {
		cout << 0 << "\n";
	}
}

void front() {
	if (qSize == 0) {
		cout << -1 << '\n';
		return;
	}
	cout << q[(f+1)%maxSize] << '\n';
}

void back() {
	if (qSize == 0) {
		cout << -1 << '\n';
		return;
	}
	cout << q[r] << '\n';
}