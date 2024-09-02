#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int row=3;row<brown-2;row++)
    {
        for(int col=3;col<brown-2;col++)
        {
            if(yellow == (row-2)*(col-2) && brown == (row*2) + (col*2-4))
            {
                answer.push_back(col);
                answer.push_back(row);
                return answer;
            }
        }        
    }
}