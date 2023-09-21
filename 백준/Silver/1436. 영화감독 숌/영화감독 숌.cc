#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n, cnt = 0;
	int num = 0;
	string buf;
	cin >> n;

	while (cnt < n)
	{
		num++;

		buf = to_string(num);

		int cnt_6 = 0;
		for (int i = 0; i < buf.size(); i++)
		{
			if (buf[i] == '6')
			{
				cnt_6++;
				if (cnt_6 == 3)
				{
					cnt++;
					break;
				}
			}
			else
			{
				cnt_6 = 0;
			}
		}
	}

	cout << num;
}