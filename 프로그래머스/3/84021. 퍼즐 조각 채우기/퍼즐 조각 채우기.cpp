#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> boardVisited;
vector<vector<int>> tableVisited;

void rotateShape(vector<pair<int, int>>& a) {
    for (int i = 0; i < a.size(); i++) {
        int rotatedX = -a[i].second;
        int rotatedY = a[i].first;
        a[i] = { rotatedX, rotatedY };
    }
}

bool isSameShape(const vector<pair<int, int>> &a, vector<pair<int, int>> b)
{
    int size = a.size();
    for (int rotate = 0; rotate < 4; rotate++)
    {
        // 첫 좌표를 기준점으로 해서 정규화
        pair<int, int> offsetA = a[0];
        pair<int, int> offsetB = b[0];

        vector<pair<int, int>> normA, normB;
        for (int i = 0; i < size; i++) {
            normA.push_back({ a[i].first - offsetA.first, a[i].second - offsetA.second });
            normB.push_back({ b[i].first - offsetB.first, b[i].second - offsetB.second });
        }

        sort(normA.begin(), normA.end());
        sort(normB.begin(), normB.end());

        if (normA == normB) return true;

        rotateShape(b);
        sort(b.begin(),b.end());
    }

    return false;
}

pair<int, int> directions[4] = { {0,1},{0,-1},{1,0},{-1,0} };
void bfs(pair<int, int> start, int checkInt, vector<vector<int>>& visited, const vector<vector<int>>& inVec, vector<vector<pair<int, int>>>& outVec) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> shape(1, start);
    pair<int, int> cur;
    q.push(start);
    visited[start.first][start.second] = 1;

    while (!q.empty()) {
        cur = q.front();
        q.pop();

        for (pair<int, int> direction : directions) {
            pair<int, int> next = { cur.first + direction.first, cur.second + direction.second };
            if (next.first < 0 || next.first >= inVec.size() || next.second < 0 || next.second >= inVec.size())
                continue;
            if (inVec[next.first][next.second] == checkInt && visited[next.first][next.second] == 0)
            {
                visited[next.first][next.second] = 1;
                q.push(next);
                shape.push_back(next);
            }
        }
    }
    outVec.push_back(shape);
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    int boardSize = game_board.size();
    vector<vector<pair<int, int>>> blanks;
    vector<vector<pair<int, int>>> puzzles;
    boardVisited.resize(boardSize, vector<int>(boardSize, 0));
    tableVisited.resize(boardSize, vector<int>(boardSize, 0));

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (game_board[i][j] == 0 && boardVisited[i][j] == 0)
                bfs({ i,j }, 0, boardVisited, game_board, blanks);

            if (table[i][j] == 1 && tableVisited[i][j] == 0)
                bfs({ i,j }, 1, tableVisited, table, puzzles);
        }
    }

    sort(blanks.begin(), blanks.end());
    sort(puzzles.begin(), puzzles.end());

    vector<bool> used(puzzles.size(), 0);
    for (auto blank : blanks)
    {
        for (int i = 0; i < puzzles.size(); i++)
        {
            if (blank.size() != puzzles[i].size()) continue;

            if (used[i] == 0 && isSameShape(blank, puzzles[i]))
            {
                answer += blank.size();
                used[i] = 1;
                break;
            }
        }
    }
    return answer;
}