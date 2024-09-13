#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct albumInfo
{
    int streamingCnt = 0;
    int mostStreamingMusicIdx1 = -1;
    int mostStreamingMusicIdx2 = -1;
};

bool compare(const albumInfo& a, const albumInfo& b)
{
    return a.streamingCnt > b.streamingCnt;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,albumInfo> m;
    
    for(int i=0;i<genres.size();i++)
    {
        if(m.find(genres[i]) == m.end())
        {
            m.insert({genres[i],{plays[i],i,-1}});
        }
        else
        {
            m[genres[i]].streamingCnt += plays[i];
            int musicIdx1 = m[genres[i]].mostStreamingMusicIdx1;
            int musicIdx2 = m[genres[i]].mostStreamingMusicIdx2;
            
            if(plays[i] > plays[musicIdx1])
            {
                m[genres[i]].mostStreamingMusicIdx1 = i;
                m[genres[i]].mostStreamingMusicIdx2 = musicIdx1;
            }
            else if (musicIdx2 == -1)
            {
                m[genres[i]].mostStreamingMusicIdx2 = i;
            }
            else if (plays[i] > plays[musicIdx2])
            {
                m[genres[i]].mostStreamingMusicIdx2 = i;
            }
        }
    }
    
    vector<albumInfo> vec;
    for(auto iter : m)
    {
        vec.push_back(iter.second);
    }
    sort(vec.begin(),vec.end(),compare);
    
    for(albumInfo a : vec)
    {
        if(a.mostStreamingMusicIdx1 != -1) answer.push_back(a.mostStreamingMusicIdx1);
        if(a.mostStreamingMusicIdx2 != -1) answer.push_back(a.mostStreamingMusicIdx2);
    }
    return answer;
}