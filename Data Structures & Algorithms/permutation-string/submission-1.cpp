class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> f1('z' - 'a' + 1,0),f2('z' - 'a' + 1,0);
        if(s2.size() < s1.size())
            return false;
        bool gasit;
        int st,dr,cont;
        for(int i=0;i<s1.size();i++)
            f1[s1[i] - 'a'] ++;
        for(int i=0;i<s1.size();i++)
            f2[s2[i] - 'a'] ++;
        st = 0;
        dr = s1.size() - 1;
        while(1)
        {
            gasit = true;
            cont = 0;
            while(cont < 'z'-'a' + 1)
            {
                if(f1[cont] != f2[cont])
                {
                    gasit = false;
                    break;
                }
                cont ++;
            }
            if(gasit == true)
                return true;
            f2[s2[st ++] - 'a'] --;
            if (dr == s2.size() - 1)
                break;
            f2[s2[++dr] - 'a'] ++;
        }
        return false;
    }
};
