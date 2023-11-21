#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int,int> &a, const pair<int,int> &b)
{
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int ans_1[5] = {1,2,3,4,5};
    int ans_2[8] = {2,1,2,3,2,4,2,5};
    int ans_3[10] = {3,3,1,1,2,2,4,4,5,5};
    
    pair<int,int> count[3] = {make_pair(0,1),make_pair(0,2),make_pair(0,3)};
    
    for(int i=0;i<answers.size();i++)
    {
        if(ans_1[i%5] == answers[i]) count[0].first++;
        if(ans_2[i%8] == answers[i]) count[1].first++;
        if(ans_3[i%10] == answers[i]) count[2].first++;
    }
    sort(count,count+3,compare);
    
    answer.push_back(count[0].second);
    for(int i =1;i<3;i++)
    {
        if(count[0].first == count[i].first)
            answer.push_back(count[i].second);
    }
    return answer;
}