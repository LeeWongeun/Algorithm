#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int w = 0,h = 0;
    
    for(int i;i<sizes.size();i++)
    {   
        if(sizes[i][0]<sizes[i][1])
        {
            swap(sizes[i][0],sizes[i][1]);
        }
        if(w<sizes[i][0]) w=sizes[i][0];
        if(h<sizes[i][1]) h=sizes[i][1];
    }
    
    answer = w*h;
    return answer;
}