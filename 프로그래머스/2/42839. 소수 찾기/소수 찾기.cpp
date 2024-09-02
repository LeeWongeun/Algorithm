#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

bool isPrime(int num)
{
    if (num < 2)
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

void permutation(const string& numbers, string& curNum, int depth, int(&selected)[7], int& answer, vector<int>& visited)
{
    if (!curNum.empty())
    {
        int cur = stoi(curNum);
        if (!visited[cur] && isPrime(cur))
        {
            visited[cur] = 1;
            answer++;
        }
    }

    if (depth == numbers.size())
    {
        return;
    }

    for (int i = 0; i < numbers.size(); i++)
    {
        if (selected[i] == 1) continue;

        selected[i] = 1;
        curNum += numbers[i];
        permutation(numbers, curNum, depth + 1, selected, answer, visited);
        selected[i] = 0;
        curNum.pop_back();
    }
}

int solution(string numbers) {
    int answer = 0;
    int selected[7] = { 0 };
    vector<int> visited(pow(10,numbers.size()), 0);
    string curNum;

    permutation(numbers, curNum, 0, selected, answer, visited);
    return answer;
}