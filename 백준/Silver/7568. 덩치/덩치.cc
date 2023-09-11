#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct person {
	int id;
	int weight;
	int height;
	int biggerPerson = 0;
	int place = 0;
};

void getInput(int &n, vector<person> &vec)
{
	person temp;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		temp.id = i;
		cin >> temp.weight >> temp.height;
		vec.push_back(temp);
	}
}

void calcPlace(vector<person>& vec)
{
	int n = vec.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (vec[i].height < vec[j].height && vec[i].weight < vec[j].weight)
			{
				vec[i].biggerPerson++;
			}
		}
		vec[i].place = vec[i].biggerPerson + 1;
	}
}

void printAns(vector<person>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].place << " ";
	}
}

int main()
{
	vector<person> vec;
	int n;

	getInput(n, vec);
	calcPlace(vec);
	printAns(vec);
}