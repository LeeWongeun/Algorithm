#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
	vector<float> scores;
	int count;
	float ave = 0, max = 0;

	cin >> count;
	for (int i = 0; i < count; i++)
	{
		float temp;
		cin >> temp;
		scores.push_back(temp);
		
		if (max < temp)
		{
			max = temp;
		}
	}

	float sum = 0;
	for (int i = 0; i < count; i++)
	{
		scores[i] = scores[i] / max * 100;
		sum += scores[i];
	}
	ave = sum / count;

	cout << ave;
}