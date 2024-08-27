#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    vector<vector<int>> D(triangle.size());
    for (int i = 1; i < triangle.size()+1; i++)
    {
        D[i - 1].resize(i);
    }

    //초기값 설정, 사이즈가 1이면 그냥 return
    D[0][0] = triangle[0][0];
    if (triangle.size() > 2)
    {
        D[1][0] = D[0][0] + triangle[1][0];
        D[1][1] = D[0][0] + triangle[1][1];
    }
    else
    {
        return D[0][0];
    }

    //바텀 업
    for (int i = 2; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (j == 0)
            {
                D[i][j] = D[i - 1][j] + triangle[i][j];
            }
            else if (j == triangle[i].size()-1)
            {
                D[i][j] = D[i - 1][j - 1] + triangle[i][j];
            }
            else
            {
                D[i][j] = max(D[i - 1][j - 1] + triangle[i][j], D[i - 1][j] + triangle[i][j]);
            }
        }
    }

    for (int i = 0; i < triangle[triangle.size() - 1].size(); i++)
    {
        if (answer < D[triangle.size() - 1][i])
        {
            answer = D[triangle.size() - 1][i];
        }
    }

    return answer;
}