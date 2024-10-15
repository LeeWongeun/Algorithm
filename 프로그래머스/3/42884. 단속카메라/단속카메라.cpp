#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    return a[0]<b[0];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end());

    vector<int> outs;

    int flag = 0;
    for (int i = 0; i < routes.size(); i++)
    {
        for (int out : outs)
        {
            if (routes[i][0] > out)
            {
                flag = 1;
                answer++;
                break;
            }
        }

        if (flag == 1)
        {
            outs = vector<int>();
            flag = 0;
        }

        outs.push_back(routes[i][1]);
    }

    return answer + 1;
}