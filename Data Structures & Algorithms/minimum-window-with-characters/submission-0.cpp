#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string rez = "";
        
        if (t.size() > s.size()) {
            return rez;
        }

        unordered_map<char, int> h;
        for (int i = 0; i < t.size(); i++) {
            h[t[i]]++;
        }

        int st = 0, dr = 0;
        int cont = t.size(); 
        int stfin = 0, drfin = INT_MAX; 
        bool sens = 1;

        while (dr < s.size() || (sens == 0 && st <= dr)) {
            if (sens == 1) {
                if (h.find(s[dr]) != h.end()) {
                    if (h[s[dr]] > 0) {
                        cont--;
                    }
                    h[s[dr]]--;
                }

                if (cont == 0) {
                    sens = 0;
                } else {
                    dr++;
                }
            } 
            else {
                if (dr - st + 1 < drfin - stfin + 1) {
                    drfin = dr;
                    stfin = st;
                }

                if (h.find(s[st]) != h.end()) {
                    h[s[st]]++;
                    if (h[s[st]] > 0) {
                        cont++;
                        sens = 1;
                        dr++;
                    }
                }
                st++;
            }
        }

        if (drfin == INT_MAX) {
            return "";
        }

        rez = s.substr(stfin, drfin - stfin + 1);
        return rez;
    }
};