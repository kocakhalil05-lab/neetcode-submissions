#include <set>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> rbt;
        vector<int> rez;
        int st = 0,dr = k - 1;
        for(int i=0;i< k ;i++)
            rbt.insert(nums[i]);
        while(1)
        {
            rez.push_back(*rbt.rbegin());
            rbt.erase(rbt.find(nums[st ++]));
            dr ++;
            if(dr == nums.size())
                break;
            rbt.insert(nums[dr]);
        }
        return rez;
    }
};
