#include <string>
#include <vector>

using namespace std;

bool canPlayDungeon(vector<int> dungeon, int cur)
{
    if(dungeon[0]<=cur)
    {
        return true;
    }
    return false;
}

//cur : 현재 피로도 cnt : 현재 돈 던전 수
void permutation(const vector<vector<int>>& dungeons, vector<int> selected, int cur, int cnt, int& outAnswer)
{   
    cnt++;
    if(cnt>outAnswer)
    {
        outAnswer = cnt;
    }
    for(int i=0;i<dungeons.size();i++)
    {
        if(selected[i] == 0 && canPlayDungeon(dungeons[i], cur))
        {
            selected[i] = 1;
            cur -= dungeons[i][1];
            permutation(dungeons, selected, cur, cnt, outAnswer);
            selected[i] = 0;
            cur += dungeons[i][1];
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    vector<int> selected(dungeons.size(), 0);
    
    permutation(dungeons, selected, k, -1, answer);
    return answer;
}