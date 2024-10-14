#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> MaxQ;
    priority_queue<int,vector<int>,greater<int>> MinQ;
    unordered_map<int,int> m;
    int size = 0;
    
    for(string operation : operations)
    {
        stringstream ss(operation);
        char op;
        int num;
        ss>>op>>num;
        
        if(op=='I')
        {
            MaxQ.push(num);
            MinQ.push(num);
            m[num]++;
            size++;
        }
        
        else if(size)
        {
            if(num == 1)
            {
                while(!m[MaxQ.top()])
                {
                    MaxQ.pop();
                }
                m[MaxQ.top()]--;
                MaxQ.pop();
                size--;
            }
            else if(num == -1)
            {
                while(!m[MinQ.top()])
                {
                    MinQ.pop();
                }
                m[MinQ.top()]--;
                MinQ.pop();
                size--;
            }
        }
    }
    while(size && !m[MaxQ.top()])
    {
        MaxQ.pop();
    }
    while(size && !m[MinQ.top()])
    {
        MinQ.pop();
    }
    if(size)
    {
        answer.push_back(MaxQ.top());
        answer.push_back(MinQ.top());
    }
    else
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}