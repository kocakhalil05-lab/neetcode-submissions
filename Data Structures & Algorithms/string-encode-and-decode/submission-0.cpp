class Solution {
public:

    string encode(vector<string>& strs) {
        string codif;
        int n;
        for(int i=0;i<strs.size();i++)
        {
            n = strs[i].size();
            if( n < 10 )
                codif += "00";
            else if(n < 100)
                codif += "0" ;
            codif += to_string(n) + strs[i];
        }
        return codif;
    }

    vector<string> decode(string s) {
        vector<string> decod;
        int i=0,n;
        while(i<s.size())
        {
            string num ;
            num += s.substr(i,3);
            n = stoi(num);
            i += 3;
            num.clear();
            decod.push_back(s.substr(i,n));
            i += n;
        }
        return decod;
    }
};
