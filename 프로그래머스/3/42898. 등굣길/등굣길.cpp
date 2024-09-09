#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>> &map, int m, int n)
{
    vector<vector<int>> isVisited(m+1,vector<int>(n+1, 0));
    queue<pair<int,int>> q;
    q.push({1,1});
    map[1][1] = 1;
    isVisited[1][1] = 1;
    int dx[2] = {1, 0};
    int dy[2] = {0, 1};
    
    while(!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();
        
        for(int i=0;i<2;i++)
        {
            int nextX = cur.first + dx[i];
            int nextY = cur.second + dy[i];
            
            //범위 밖인 경우 제외
            if(nextX > m || nextY > n) continue;
            if(map[nextX][nextY] != -1 && isVisited[nextX][nextY] == 0)
            {
                q.push({nextX,nextY});
                isVisited[nextX][nextY] = 1;
                int up = ( map[nextX][nextY-1] == -1) ? 0 : map[nextX][nextY-1];
                int left = ( map[nextX-1][nextY] == -1) ? 0 : map[nextX-1][nextY];
                map[nextX][nextY] = (up + left) % 1000000007;
            }            
        }
    }
    
    return map[m][n];
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    //-1 : 침수 -2 : 아직 구하지 않은 경우의 수
    vector<vector<int>> map(m+1,vector<int>(n+1,0));
    
    //침수지역 -1로 초기화
    for(int i=0;i<puddles.size();i++)
    {
        map[puddles[i][0]][puddles[i][1]] = -1;
    }

    answer = bfs(map, m, n);
    return answer == -2 ? 0 : answer;
}