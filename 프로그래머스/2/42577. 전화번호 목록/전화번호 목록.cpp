#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrefix(const string& a, const string& b)
{
    if(b.find(a) == 0) return true;
    
    return false;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    
    for(int i=0;i<phone_book.size() - 1;i++)
    {
        if(isPrefix(phone_book[i],phone_book[i+1]))
        {
            return false;
        }
    }
    return answer;
}