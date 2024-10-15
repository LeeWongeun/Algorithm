#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    int minIdx = 0;
    int maxIdx = people.size()-1;
    
    while(minIdx <= maxIdx)
    {
        if(people[minIdx] + people[maxIdx] <= limit)
        {
            minIdx++;
            maxIdx--;
        }
        else
        {
            maxIdx--;
        }
        answer++;
    }
    
    return answer;
}