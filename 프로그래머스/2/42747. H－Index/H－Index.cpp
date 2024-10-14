#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int maxH = citations.size();
    
    sort(citations.begin(), citations.end(), greater<>());
    
    for(int h=1; h<=maxH; h++)
    {   
        for(int i=0;i<citations.size();i++)
        {
            if(citations[i] < h)
            {
                if(i >= h && answer < h)
                {
                    answer = h;
                }
                break;
            }
            if(i+1 == h)
            {
                answer = h;
            }
        }
    }
    return answer;
}