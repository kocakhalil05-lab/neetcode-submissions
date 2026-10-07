#include <unordered_map>
#include<string>
class Solution {
public:
    string freq(string s)
    {
        vector<int> rez('z'-'a' + 1,0);
        int size = s.size();
        for(int i=0;i < size;i++)
        {
            rez[s[i] - 'a'] ++;
        }
        string rez_s;
        for(int i=0;i<'z'-'a'+1;i++)
        {
            rez_s += to_string(rez[i]) + "#";
        }
        return rez_s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map < string , int > hash;
        vector<vector<string>> rez;
        int n = strs.size(),cont = 1;
        for(int i=0;i<n;i++)
        {
            int x = hash[freq(strs[i])];
            if(x != 0)
                rez[x-1].push_back(strs[i]);
            else
            {
                hash[freq(strs[i])] = cont ++;
                vector<string> vec;
                vec.push_back(strs[i]);
                rez.push_back(vec);
            }
        }
        return rez;
    }
};
