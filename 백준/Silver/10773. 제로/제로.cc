#include <iostream>
#include <stack>
#include <numeric>

using namespace std;

int getInput_calcAns(int &k)
{
	stack<int> s;
	int a, ans = 0;
	cin >> k;
	
	for (int i = 0; i < k; i++)
	{
		cin >> a;
		if (a == 0)
		{
			s.pop();
		}
		else
		{
			s.push(a);
		}
	}
	
	while (!s.empty())
	{
		ans += s.top();
		s.pop();
	}

	return ans;
}

int main()
{
	int k;

	int ans = getInput_calcAns(k);

	cout << ans;
}