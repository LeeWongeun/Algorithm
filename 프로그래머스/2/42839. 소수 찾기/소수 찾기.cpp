#include <string>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

int answer = 0;
int visited[10000000] = { 0 };

int vtoi(vector<int> vec)
{
    int num = 0;

    for (int i = 0; i < vec.size(); i++)
    {
        num = num * 10 + vec[i];
    }

    return num;
}

bool isPrime(int num)
{
    if (num == 1 || num == 0)
    {
        return false;
    }

    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

void DFS(vector<int> numbers, int startIndex, int k, vector<int> selected, vector<int> vec)
{
    int a = vtoi(vec);

    if (visited[a] == 0)
    {
        visited[a] = 1;
        if (isPrime(a))
        {
            answer++;
        }
    }

    if (vec.size() == k) return;

    for (int i = 0; i < k; i++)
    {
        if (selected[i] == 1) continue;

        vec.push_back(numbers[i]);
        selected[i] = 1;
        DFS(numbers, i, k, selected, vec);
        vec.pop_back();
        selected[i] = 0;
    }
}

int solution(string numbers) {
    vector<int> numbersVec;
    for (int i = 0; i < numbers.size(); i++)
    {
        numbersVec.push_back(numbers[i] - '0');
    }

    vector<int> selected(numbersVec.size());
    vector<int> vec;

    for (int i = 1; i <= numbers.size(); i++)
    {
        DFS(numbersVec, 0, i, selected, vec);
    }
    return answer;
}