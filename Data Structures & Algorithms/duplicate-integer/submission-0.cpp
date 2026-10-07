#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,bool> hash_map;
        for(int i=0;i<nums.size();i++)
        {
            if(hash_map[nums[i]] == true)
                return true;
            hash_map[nums[i]] = true;
        }
        return false;
    }
};