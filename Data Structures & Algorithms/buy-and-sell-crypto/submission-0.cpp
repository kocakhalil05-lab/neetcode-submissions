class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0,st = 0,cur = 1;
        while(cur < prices.size())
        {
            if(prices[cur] > prices[st])
            {
               if(prices[cur] - prices[st] > max)
                    max = prices[cur] - prices[st]; 
            }
            else 
                st = cur;
            cur ++;       
        }
        return max;
    }
};
