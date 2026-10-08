#include <stack>
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack <int> poz,temp;
        vector<int> rez(temperatures.size());
        int cur;
        for(int i=0;i<temperatures.size();i++)
        {
            cur = temperatures[i];
            while(!temp.empty() && temp.top() < cur)
            {
                rez[poz.top()] = i - poz.top();
                temp.pop();
                poz.pop();
            }
            temp.push(cur);
            poz.push(i);
        }
        while(!temp.empty())
        {
            rez[poz.top()] = 0;
            poz.pop();
            temp.pop();
        }
        return rez;
    }
};
