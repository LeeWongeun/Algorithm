#include <iostream>
#include <vector>

using namespace std;

string Min = "9999999999";
string Max = "0000000000";

void dfs(string cur, vector<bool> selected, int depth, const vector<char>& signs)
{
	if (cur.length() > 1)
	{
		if (signs[cur.length() - 2] == '>')
		{
			if (!(cur[cur.length()-2] > cur.back())) return;
		}
		else
		{
			if (!(cur[cur.length() - 2] < cur.back())) return;
		}
	}

	if (cur.length() == depth)
	{
		Max = max(cur, Max);
		Min = min(cur, Min);
		return;
	}

	for (char i = '0'; i <= '9'; i++)
	{
		if (selected[i - '0'] == 1) continue;
		
		selected[i - '0'] = 1;
		cur = cur + i;
		dfs(cur, selected, depth, signs);
		selected[i - '0'] = 0;
		cur.pop_back();
	}
}

int main()
{
	int n;
	cin >> n;

	vector<char> signs(n);
	for (int i = 0; i < n; i++)
	{
		cin >> signs[i];
	}

	vector<bool> selected(10, 0);
	dfs("", selected, n + 1, signs);

	cout << Max << '\n' << Min;
}