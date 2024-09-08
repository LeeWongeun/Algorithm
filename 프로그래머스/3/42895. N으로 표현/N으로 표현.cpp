#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int getNN(int N, int cnt)
{
    int a = N;
    for(int i=0;i<cnt;i++)
    {
        a = a*10+N;
    }
    return a;
}

int solution(int N, int number) {
    vector<unordered_set<int>> d(8);
    for (int i = 0; i < 8; ++i)
    {
        d[i].insert(stoi(string(i + 1, '0' + N))); 
        
        for (int j = 0; j < i; ++j)
        {
            for (int op1 : d[j])
            {
                for (int op2 : d[i - j - 1])
                {
                    d[i].insert(op1 + op2);
                    d[i].insert(op1 - op2);
                    d[i].insert(op1 * op2);
                    if (op2 != 0) d[i].insert(op1 / op2);
                }
            }
        }
    }
    for(int i=0;i<8;i++)
    {
        if(d[i].find(number) != d[i].end()) return i+1;
    }
    
    return -1;
}