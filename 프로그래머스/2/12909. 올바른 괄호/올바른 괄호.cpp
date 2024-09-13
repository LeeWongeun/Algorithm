#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string str)
{
    bool answer = true;
    stack<char> s;
    
    for(char a : str)
    {
        if(a == ')')
        {
            if (s.empty())
            {
                return false;
            }
            if(s.top() != '(')
            {
                return false;
            }
            
            s.pop();
        }
        else
        {
            s.push(a);
        }
    }
    
    if(!s.empty())
    {
        return false;
    }
    
    return answer;
}