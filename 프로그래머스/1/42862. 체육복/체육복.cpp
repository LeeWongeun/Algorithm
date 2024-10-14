#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    sort(lost.begin(),lost.end());
    sort(reserve.begin(), reserve.end());
    vector<int> vec(n+1,1);
    
    for(int i: reserve)
    {
        vec[i] = 2;
    }
    for(int i : lost)
    {
        vec[i]--;
    }
    
    for(int i:reserve)
    {
        if(vec[i] <= 1) continue;
        
        if(i-1 > 0 && vec[i-1] == 0)
        {
            vec[i-1] = 1;
        }
        else if(i+1 <= n && vec[i+1] == 0)
        {
            vec[i+1] = 1;
        }
    }
    
    for(int i:vec)
    {
        if(i > 0) answer++;
    }
    //편의상 배열을 1 크게 설정했으므로
    answer--;
    
    return answer;
}