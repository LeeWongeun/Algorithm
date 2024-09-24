#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int curP = 1e9, prevP = 1e9;
    
    //우선순위, location
    queue<pair<int,int>> q;
    priority_queue<int> pq;
    for(int i=0;i<priorities.size();i++)
    {
        q.push({priorities[i],i});
        pq.push(priorities[i]);
    }
    
    while(!q.empty())
    {
        curP = pq.top();
        pq.pop();
        
        int size = q.size();
        for(int j=0; j<size; j++)
        {
            if(q.front().first == curP)
            {
                answer++;
                if(q.front().second == location) return answer;
                q.pop();
                break;
            }
            else
            {
                q.push(q.front());
                q.pop();
            }
        }
    }
}