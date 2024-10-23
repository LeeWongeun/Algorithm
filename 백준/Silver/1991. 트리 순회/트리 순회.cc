#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

string pre;
string in;
string post;

unordered_map<char,pair<char, char>> nodes;
void preorder(char cur)
{
	if (cur == '.') return;

	pre += cur;

	preorder(nodes[cur].first);
	preorder(nodes[cur].second);
}

void inorder(char cur)
{
	if (cur == '.') return;

	inorder(nodes[cur].first);
	in += cur;
	inorder(nodes[cur].second);
}

void postorder(char cur)
{
	if (cur == '.') return;

	postorder(nodes[cur].first);
	postorder(nodes[cur].second);
	post += cur;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char root, left, right;
		cin >> root >> left >> right;
		pair<int, int> children = { left,right };
		nodes.insert({ root,children });
	}

	preorder('A');
	inorder('A');
	postorder('A');

	cout << pre << '\n';
	cout << in << '\n';
	cout << post << '\n';
}