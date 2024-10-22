#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int bs(const vector<int>& rocks, int n, int start, int end, int distance)
{
    int mid;
    int result = 0;

    while (start <= end)
    {
        mid = (start + end) / 2;
        int prev = 0;
        int cnt = 0; // 돌을 없앤 횟수

        for (int i = 0; i < rocks.size(); i++)
        {
            if (mid > rocks[i] - prev)
            {
                cnt++;
                continue;
            }
            prev = rocks[i];
        }

        if (mid > distance - prev)
        {
            cnt++;
        }

        if (cnt <= n)
        {
            start = mid + 1;
            result = max(result, mid);
        }
        else
        {
            end = mid - 1;
        }
    }

    return result;
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;

    sort(rocks.begin(), rocks.end());
    answer = bs(rocks, n, 0, distance, distance);
    return answer;
}