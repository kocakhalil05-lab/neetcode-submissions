class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stiva;
        int cur = 0,start = 0 ,sens = 1,vol = 0;///luam la dreapta
        while(cur < height.size() - 1)
        {
            cur += sens;
            if(height[cur] >= height[start])
            {
                while(!stiva.empty())
                {
                    vol += height[start] - stiva.top();
                    stiva.pop();
                }
                    
                start = cur;
                stiva.push(height[start]);
            }
            else
                stiva.push(height[cur]);
        }
        if (cur != start)
        {
            sens = -1;
            start = cur;
            stiva.pop();
            while(!stiva.empty())
            {
                cur += sens;
                if(height[cur] > height[start])
                {
                    start = cur;
                }   
                else
                {
                    vol += height[start] - stiva.top();
                }   
                stiva.pop();
            }
        }
        return vol;
    }
};
