#include <string>
#include <vector>

using namespace std;

int maxSub = 0;
int maxMoney = 0;
vector<int> discountVec;

void calculate(const vector<vector<int>>& users, const vector<int>& emoticons)
{
    int totalSub = 0;
    int totalMoney = 0;
    for (int i = 0; i < users.size(); i++)
    {
        int usedMoney = 0;
        for (int j = 0; j < emoticons.size(); j++)
        {
            if (users[i][0] > discountVec[j]) continue;
            usedMoney += emoticons[j] - (emoticons[j] * ((float)discountVec[j]/100));
        }

        if (usedMoney >= users[i][1])
        {
            totalSub++;
        }
        else
        {
            totalMoney += usedMoney;
        }
    }

    if (maxSub < totalSub)
    {
        maxSub = totalSub;
        maxMoney = totalMoney;
    }
    else if (maxSub == totalSub)
    {
        maxMoney = max(maxMoney, totalMoney);
    }
}

void dfs(int curDepth, int depth, const vector<vector<int>>& users, const vector<int>& emoticons)
{
    if (curDepth == depth)
    {
        calculate(users, emoticons);
        return;
    }

    for (int discount = 10; discount <= 40; discount += 10)
    {
        discountVec[curDepth] = discount;
        dfs(curDepth + 1, depth, users, emoticons);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    discountVec.resize(emoticons.size(), 0);

    dfs(0, emoticons.size(), users, emoticons);

    answer.push_back(maxSub);
    answer.push_back(maxMoney);
    return answer;
}