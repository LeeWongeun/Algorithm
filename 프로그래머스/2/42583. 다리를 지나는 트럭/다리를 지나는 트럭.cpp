#include <string>
#include <vector>
#include <queue>

using namespace std;

int sum(const vector<int>& vec)
{
    int sum=0;
    for(int i : vec)
    {
        sum+=i;
    }
    return sum;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    vector<int> bridge(bridge_length, 0);
    queue<int> q;
    for(int i : truck_weights)
    {
        q.push(i);
    }
    
    while(!q.empty())
    {
        answer++;
        
        for(int i=bridge.size()-1;i>0;i--)
        {
            bridge[i] = bridge[i-1];
            bridge[i-1] = 0;
        }
        
        if(sum(bridge) + q.front() <= weight)
        {
            bridge[0] = q.front();
            q.pop();
        }
    }
    
    for(int i=0;i<bridge.size(); i++)
    {
        if(bridge[i]!=0)
        {
            answer += bridge.size() - i;
            break;
        }
    }
    return answer;
}