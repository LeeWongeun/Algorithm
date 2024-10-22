#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v(n+1);
    v[1] = 1;
    v[2] = 2;
    v[3] = 3;

    for(int i=4; i<=n; i++)
    {
        v[i] = (v[i-1] + v[i-2])%1000000007;
    }

    answer = v[n];
    return answer;
}