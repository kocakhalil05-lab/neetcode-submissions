class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> apar(2001,0),fin;
        vector<vector<int>> rez(n + 1);
        for(int i=0;i<n;i++)
            apar[nums[i] + 1000] ++;
        for(int i=0;i<2001;i++)
            rez[apar[i]].push_back(i - 1000);
        for(int i=n;i>=0;i--)
        {
            if(k>rez[i].size())
            {
                k-=rez[i].size();
                while(rez[i].size()>0)
                {                  
                    fin.push_back(rez[i].back());
                    rez[i].pop_back();
                }
            }
            else
                while(k > 0)
                {
                   fin.push_back(rez[i].back());
                   rez[i].pop_back(); 
                   k--;  
                }
        }
        return fin;
    }
};
