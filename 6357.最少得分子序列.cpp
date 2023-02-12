class Solution {
public:
    int minimumScore(string s, string t) {
        int p = 0;
        vector<int> posL, posR;
        for (int i = 0; i < t.size(); i++) {
            while (p < s.size() && s[p] != t[i]) p++;
            if (p == s.size()) break;
            posL.push_back(p);
            p++;
        }
        p = s.size() - 1;
        for (int i = t.size()-1; i >= 0; i--) {
            while (p >= 0 && s[p] != t[i]) p--;
            if (p < 0) break;
            posR.push_back(p);
            p--;
        }
        int p1 = posL.size() - 1, p2 = -1;
        // while (p2 + 1 < posR.size() && posR[p2+1] > posL[p1]) p2++;
        int minans = t.size();
        while (p1 >= 0) {
            while (p2 + 1 < posR.size() && posR[p2+1] > posL[p1]) p2++;
            minans = max(0, min(minans, (int)(t.size() - (p1+1) - (p2+1))));
            p1--;
        }
        minans = min(minans, (int)(t.size() - posR.size()));
        return minans;
    }
};