#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long bs(const vector<int>& times, long long start, long long end, int n)
{
    long long result = 0;
    while (start <= end)
    {
        long long mid = (start + end) / 2;

        long long sum = 0;
        for (int time : times)
        {
            sum += mid / time;
        }

        if (n <= sum)
        {
            result = mid;
            end = mid - 1;
        }
        else if (n > sum) start = mid + 1;
    }

    return result;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;

    long long start = times[0];
    for (int time : times)
    {
        start = min(start, (long long)time);
    }
    long long end = n * start;

    answer = bs(times, start, end, n);

    return answer;
}