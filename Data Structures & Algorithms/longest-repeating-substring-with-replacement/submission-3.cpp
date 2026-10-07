#include <unordered_map>
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> hash; 
        int st = 0 ,dr = 1,lung = 1,max_car = 1;
        bool ok =true;
        char c = s[0];
        hash[s[0]] = 1;
        while(st <= dr && dr < s.size())
        {
            if(ok == true)
            {
                hash[s[dr]] ++;
                ok = false;
            }
            if(hash[s[dr]] > max_car)
            {
                max_car = hash[s[dr]];
                c = s[dr];
            }   
            if((dr - st + 1) - max_car <= k)
            {
                if((dr - st + 1)>lung)
                    lung = (dr - st + 1);
                dr ++;
                ok = true;
            }
            else
            {
                hash[s[st]] -- ;
                st ++;
            }    
        }
        return lung;
    }
};
