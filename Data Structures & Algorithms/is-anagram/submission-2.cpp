#include <unordered_map>
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        int n=s.size();
        int apar['z' - 'a' + 1] = {0};
        for(int i=0;i<n;i++)
        {
            apar[ s[i] - 'a'] ++;
        }
        for(int i=0;i<n;i++)
        {
            apar[ t[i] - 'a'] --;
        }
        for(int i=0;i<'z'-'a'+1;i++)
            if(apar[i]!= 0 )
                return false;
        return true;
    }
};
