#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> answer;
vector<int> selected;

long long factorial(int n)
{
    if (n == 0 || n == 1) return n;
    return n * factorial(n - 1);
}

int findNotSelected(int inCnt)
{
    int cnt = 0;

    for (int i = 1; i < selected.size(); i++)
    {
        if (selected[i] == 1) continue;

        cnt++;
        if (cnt == inCnt) return i;
    }
}

void r(int n, long long k)
{

    if (n == 1)
    {
        answer.push_back(findNotSelected(1));
        return;
    }
    int nextCnt = ceil((float)k / factorial(n - 1));
    int nextPerson = findNotSelected(nextCnt);
    selected[nextPerson] = 1;
    answer.push_back(nextPerson);
    k -= (factorial(n - 1) * (nextCnt - 1));

    r(n - 1, k);
}

vector<int> solution(int n, long long k) {
    selected.resize(n + 1, 0);
    r(n, k);
    return answer;
}