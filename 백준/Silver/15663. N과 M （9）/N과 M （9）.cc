#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

set<vector<int>> answer;

void dfs(const vector<int>& vec, vector<int> selected, vector<int> curVec, int curDepth, int depth)
{
	if (curDepth == depth)
	{
		answer.insert(curVec);
		return;
	}

	for (int i = 0; i < vec.size(); i++)
	{
		if (selected[i] == 1) continue;
		selected[i] = 1;
		curVec.push_back(vec[i]);
		dfs(vec, selected, curVec, curDepth + 1, depth);
		selected[i] = 0;
		curVec.pop_back();
	}
}

int main()
{
	int n,m;
	cin >> n >> m;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	vector<int> selected(vec.size(), 0);
	vector<int> curVec;
	dfs(vec, selected, curVec, 0, m);

	for (auto v : answer)
	{
		for (int a : v)
		{
			cout << a << ' ';
		}
		cout << '\n';
	}
}