#include <string>
#include <vector>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 1e9;
    vector<vector<int>> d(n+1,vector<int>(n+1,1000000));
    
    for(int i=0;i<=n;i++)
    {
        d[i][i] = 0;
    }
    
    for(int i=0;i<fares.size();i++)
    {
        d[fares[i][0]][fares[i][1]] = fares[i][2];
        d[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    
    for(int k=1;k<=n;k++)
    {
        for(int s=1;s<=n;s++)
        {
            for(int e=1;e<=n;e++)
            {
                d[s][e] = min(d[s][e], d[s][k] + d[k][e]);
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        answer = min(answer, d[s][i] + d[i][a] + d[i][b]);
    }
    
    return answer;
}