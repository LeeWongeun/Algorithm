#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> unionVec;

bool compare(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int find(int a)
{
    if (unionVec[a] == a) return a;

    return find(unionVec[a]);
}

void u(int a, int b)
{
    unionVec[find(b)] = find(a);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int cnt = 0;

    sort(costs.begin(), costs.end(), compare);
    unionVec.resize(n);
    for (int i = 0; i < n; i++)
    {
        unionVec[i] = i;
    }

    for (vector<int> cost : costs)
    {
        if (cnt >= n - 1) break;

        if (find(cost[0]) == find(cost[1])) continue;

        u(cost[0], cost[1]);
        cnt++;
        answer += cost[2];
    }
    return answer;
}