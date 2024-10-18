#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;

    for (int i = 0; i <= d; i+=k)
    {
        answer += floor(sqrt((long long)pow(d, 2) - (long long)pow(i, 2)) / k);
        answer++; //축 위의 점
    }
    return answer;
}