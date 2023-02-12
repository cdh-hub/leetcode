class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> map;
        
        for (int len = 1; len <= 30; len++) {
            if (len - 1 >= s.size()) break;
            int num = 0;
            for (int i = 0; i < len; i++) {
                num = (num << 1) | (s[i] - '0');
            }
            if (!map.count(num)) map[num] = vector<int>({0,len-1});
            for (int i = 1; i + len - 1 < s.size(); i++) {
                num = (((num << 1) | (s[i+len-1] - '0')) | (1 << len)) - (1 << len);
                if (!map.count(num)) map[num] = vector<int>({i,i+len-1});
            }
        }
        
        vector<vector<int>> ans;
        for (auto q: queries) {
            if (map.count(q[0]^q[1])) ans.push_back(map[q[0]^q[1]]);
            else ans.push_back({-1,-1});
        }
        
        return ans;
    }
};