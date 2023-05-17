#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
	if (a.length() == b.length())
	{
		return a < b;
	}
	else {
		return a.length() < b.length();
	}
}
int main()
{
	vector<string> vec;
	int n;
	string buf;

	cin >> n;

	for (int i=0; i < n; i++)
	{
		cin >> buf;
		vec.push_back(buf);
	}

	sort(vec.begin(), vec.end(), compare);
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << endl;
	}
}