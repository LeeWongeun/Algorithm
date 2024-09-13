#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int front = 0;
    
    while(front < progresses.size())
    {
        for(int i=0;i<progresses.size();i++)
        {
            progresses[i] += speeds[i];
        }
        
        int cnt = 0;
        for(int i=front;i<progresses.size();i++)
        {
            if(progresses[i] < 100)
            {
                break;
            }
            cnt++;
            front = i + 1;
        }
        
        if(cnt != 0)
        {
            answer.push_back(cnt);
        }
    }
    
    return answer;
}