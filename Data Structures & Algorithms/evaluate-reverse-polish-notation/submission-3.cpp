#include <stack>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> stiva;
        int x,y;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i].size() == 1 &&(tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' || tokens[i][0] == '/'))
            {
                if(stiva.empty())
                    return -1;
                y = stiva.top();
                stiva.pop();
                if(stiva.empty())
                    return -1;
                x = stiva.top();
                stiva.pop();
                if(tokens[i][0] == '+')
                    x += y;
                if(tokens[i][0] == '-')
                    x -= y;
                if(tokens[i][0] == '*')
                    x *= y;
                if(tokens[i][0] == '/')
                    x /= y;
                stiva.push(x);
            }
            else
                stiva.push(stoi(tokens[i]));
        }
        return stiva.top();
    }
};
