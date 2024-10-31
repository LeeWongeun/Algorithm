#include <vector>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < edge_list.size(); i++)
    {
        adj[edge_list[i][0]].push_back(edge_list[i][1]);
        adj[edge_list[i][1]].push_back(edge_list[i][0]);
    }

    vector<vector<int>> d(gps_log.size(), vector<int>(n + 1, 1e9));
    d[0][gps_log[0]] = 0;
    for (int t = 1; t < gps_log.size(); t++)
    {
        for (int i = 1; i <= n; i++)
        {
            d[t][i] = min(d[t][i], d[t - 1][i] + (i == gps_log[t] ? 0 : 1));
            for (int next : adj[i])
            {
                if (next == gps_log[t]) d[t][next] = min(d[t][next], d[t - 1][i]);
                else d[t][next] = min(d[t][next], d[t - 1][i] + 1);
            }
        }
    }

    answer = d.back()[gps_log.back()];
    answer = answer == 1e9 ? -1 : answer;
    return answer;
}