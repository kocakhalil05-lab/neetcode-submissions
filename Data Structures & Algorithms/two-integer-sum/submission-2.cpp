#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        vector<int> rez;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(hash[target - nums[i]] != 0)
            {
                rez.push_back(hash[target-nums[i]]-1);
                rez.push_back(i);
                return rez;
            }
            else
                hash[nums[i]] = i + 1;
        }
        return rez;
    }
};
