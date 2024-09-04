#include <string>
#include <vector>

using namespace std;


void dfs(const vector<int>& numbers, int depth, int target, int cur, int next, int& outAnswer)
{
    cur += next;
    if(depth == numbers.size())
    {
        if(target == cur)
        {
            outAnswer++;
        }
        return;
    }
    dfs(numbers, depth+1, target, cur, -numbers[depth], outAnswer);
    dfs(numbers, depth+1, target, cur, numbers[depth], outAnswer);
}


int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(numbers, 0, target, 0, 0, answer);
    
    return answer;
}