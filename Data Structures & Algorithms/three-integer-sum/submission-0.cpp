class Solution {
public:
    bool verif(vector<vector<int>> rez,int i ,int j,int k)
    {
        for(int cont=0;cont<rez.size();cont++)
        {
           if(rez[cont][0] == i && rez[cont][1] == j && rez[cont][2] == k)
            return false; 
        }
        return true;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> rez;
        int st,dr,sum;
        for(int i=0;i<nums.size() - 1;i++)
        {
            st = i + 1;
            dr = nums.size() -1;
            sum = nums[i];
            while(st < dr)
            {
                if(sum + nums[st] + nums[dr] == 0)
                {
                    if(verif(rez,nums[i],nums[st],nums[dr]))
                    {
                        rez.push_back({nums[i] ,nums[st],nums[dr]});
                    }
                    st ++;
                    dr --;
                }
                else if (sum + nums[st] + nums[dr] > 0)
                    dr --;
                    else
                        st ++;
            }
        }
        return rez;
    }
};
