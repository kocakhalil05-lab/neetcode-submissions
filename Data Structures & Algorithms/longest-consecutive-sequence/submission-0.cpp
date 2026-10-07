#include <unordered_map>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map <int,int> hash;
        int n = nums.size(), max = 0, x;
        for(int i=0;i<n;i++)
        {
            x = nums[i];
            if( hash[x]!= 0 )
                continue;
            hash[x] = 1;
            hash[x] += hash[x-1];
            while(hash[x+1] != 0)
            {
                hash[x+1]=hash[x] + 1; 
                x++;
            }
            if(hash[x] > max)
                max = hash[x];
        }
        return max;
    }
};
