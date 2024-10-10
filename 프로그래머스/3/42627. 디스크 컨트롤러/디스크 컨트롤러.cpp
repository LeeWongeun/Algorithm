#include <string>
#include <vector>
#include <queue>

using namespace std;

struct compare
{
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        if(a.second==b.second)
            return a.first > b.first;
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    vector<int> ans;
    priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
    int curTime = 0;
    
    while(!pq.empty() || !jobs.empty())
    {
        for(int i = 0; i<jobs.size();)
        {
            if(jobs[i][0] <= curTime)
            {
                pq.push({jobs[i][0],jobs[i][1]});
                jobs.erase(jobs.begin()+i);
            }
            else
            {
                i++;
            }
        }
        //ans에 추가 후 현재 시간 갱신
        if(!pq.empty())
        {
            ans.push_back(pq.top().second + curTime - pq.top().first);
            curTime += pq.top().second;
            pq.pop();   
        }
        else
        {
            curTime++;
        }
    }
    
    int sum=0;
    for(int i : ans)
    {
        sum+=i;
    }
        
    answer = sum / ans.size();
    return answer;
}