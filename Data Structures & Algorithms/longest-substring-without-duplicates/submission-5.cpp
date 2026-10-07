#include <unordered_map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hash;
        int start = 0,cur = 1,max = 1,n = s.size(),lung = 1;
        if (s.size() == 0)
            return 0;
        hash[s[0]] = 1;
        char c;
        while(cur < n)
        {
            c = s[cur];
            if(hash[c] == 0)
                lung ++;
            else
            {
                if(lung > max)
                    max = lung;
                for(int i=start; i< hash[c] - 1;i++)
                    hash[s[i]] = 0;
                start = hash[c];
                lung = cur - start + 1;
            }
            hash[c] = ++cur;
        }
        if(lung > max)
            max = lung;
        return max;
    }
};
