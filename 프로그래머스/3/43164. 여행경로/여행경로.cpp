#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> used;
bool isAnswer = 0;
void dfs(string start, const vector<vector<string>>& tickets, int cnt, vector<string>& outAnswer) {
    if (cnt == tickets.size()) {
        isAnswer = 1;
    }

    outAnswer.push_back(start);

    for (int i = 0; i < tickets.size(); i++) {
        if (used[i] == 1 || tickets[i][0] != start) continue;
        used[i] = 1;
        dfs(tickets[i][1], tickets, cnt + 1, outAnswer);
        if (isAnswer == 0) {
            outAnswer.pop_back();
            used[i] = 0;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end());
    used.resize(tickets.size(), 0);

    int cnt = 0;
    dfs("ICN", tickets, cnt, answer);

    return answer;
}