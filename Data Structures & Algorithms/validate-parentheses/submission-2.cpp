#include <stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char> stiva;
        if(s.size() % 2 != 0)
            return false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{' )
                stiva.push(s[i]);
            else
            {
                if(stiva.empty())
                    return false;
                if(stiva.top() == '(' && s[i] != ')')
                    return false;
                if(stiva.top() == '[' && s[i] != ']')
                    return false;
                if(stiva.top() == '{' && s[i] != '}')
                    return false;
                stiva.pop();
            }
        }
        if(stiva.empty())
            return true;
        else
            return false;
    }
};
