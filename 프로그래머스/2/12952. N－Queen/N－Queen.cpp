#include <string>
#include <vector>

using namespace std;

int answer = 0;

/*
퀸을 둔다.
둔 시점에서 공격이 가능하면 퀸을 빼고 다음 위치에 둬본다.
*/

bool canAttack(const vector<int>& board, int curDepth)
{
    for (int i = 0; i < curDepth; i++)
    {   
        if (board[i] == board[curDepth]) return true; //같은 줄
        else if (abs(board[i] - board[curDepth]) == abs(i - curDepth)) return true; // 대각 선
    }
    return false;
}

void dfs(int n, int curDepth, vector<int> board)
{
    if (n == curDepth)
    {
        answer++;
        return;
    }

    for(int i=0;i<n;i++)
    {
        board[curDepth] = i;
        if(canAttack(board,curDepth)) continue;
        dfs(n,curDepth+1,board);
    }
}

int solution(int n) {
    vector<int> board(n, -1);

    dfs(n, 0, board);
    return answer;
}