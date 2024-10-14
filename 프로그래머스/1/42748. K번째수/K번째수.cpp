#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(vector<int> command : commands)
    {
        int start = command[0];
        int end = command[1];
        int K = command[2];
        
        vector<int> vec;
        for(int i=start-1;i<end;i++)
        {
            vec.push_back(array[i]);
        }
        sort(vec.begin(), vec.end());
        
        answer.push_back(vec[K-1]);
    }
    return answer;
}